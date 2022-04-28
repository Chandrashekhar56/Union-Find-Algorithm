#include <bits/stdc++.h>
using namespace std;
struct Graph_Edge
{
	int source_vertex, destination_vertex;
};

struct Graph_for_find_union
{
	int total_Vertices, total_Edges;
	struct Graph_Edge* edge;
};

struct subset
{
	int p;
	int r;
};


struct Graph_for_find_union* create_graph(int total_Vertices, int total_Edges)
{
	struct Graph_for_find_union* g = (struct Graph_for_find_union*)malloc(sizeof(struct Graph_for_find_union));
	g->total_Vertices =total_Vertices;
	g->total_Edges = total_Edges;
	g->edge = (struct Graph_Edge*)malloc(g->total_Edges * sizeof(struct Graph_Edge));
	return g;
}
int search(struct subset s[], int x)
{
	if (s[x].p!= x)
		s[x].p= search(s, s[x].p);
	return s[x].p;
}

void function_of_union(struct subset s[], int root_of_x, int root_of_y)
{
	if (s[root_of_x].r < s[root_of_y].r)
		s[root_of_x].p = root_of_y;
	else if (s[root_of_x].r > s[root_of_y].r)
		s[root_of_y].p = root_of_x;
	else {
		s[root_of_y].p = root_of_x;
		s[root_of_x].r++;
	}
}

int function_of_find_iscycle(struct Graph_for_find_union* g)
{
	int total_Vertices = g->total_Vertices;
	int total_Edges = g->total_Edges;
	struct subset* s = (struct subset*)malloc(total_Vertices * sizeof(struct subset));

	for (int j = 0; j < total_Vertices; ++j)
    {
            s[j].p = j;
            s[j].r = 0;
    }
	for (int k = 0; k < total_Edges; ++k)
    {
            int m = search(s, g->edge[k].source_vertex);
            int n = search(s, g->edge[k].destination_vertex);

            if (m == n)
			return 1;

            function_of_union(s, m, n);
    }
	return 0;
}

int main()
{

	int total_Vertices = 3,total_Edges = 3;
	struct Graph_for_find_union* g = create_graph(total_Vertices,total_Edges);

	g->edge[1].source_vertex = 1;
	g->edge[1].destination_vertex = 2;

	g->edge[2].source_vertex = 2;
	g->edge[2].destination_vertex = 3;

	g->edge[3].source_vertex = 1;
	g->edge[3].destination_vertex = 3;

	if (function_of_find_iscycle(g))
		cout << "cycle is present in graph";
	else
		cout << "cycle is not present in graph";

	return 0;
}

