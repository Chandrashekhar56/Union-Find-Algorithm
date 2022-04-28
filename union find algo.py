from collections import defaultdict
class Graph_for_find_union:

	def __init__(self, total_Vertices):
		self.total_Vertices = total_Vertices
		self.graph_edges = defaultdict(list)
		
	def add_new_edge(self,source_vertex,destination_vertex): 
		self.graph_edges[source_vertex].append(destination_vertex)
		

def function_of_find_iscycle(g):
	arr= []

	for x in range(g.total_Vertices):
		arr.append(Subset(x, 0))

	for x in g.graph_edges:
		x_rep = search(arr, x)
		
		for y in g.graph_edges[x]:
			y_rep = search(arr, y)

			if x_rep == y_rep:
				return True
			else:
				function_of_union(arr, x_rep, y_rep)
				
class Subset:
	def __init__(self, p, r):
		self.p = p #p for parent
		self.r = r #r for rank

def search(arr, vertex):
    
	if arr[vertex].p != vertex:
		arr[vertex].p = search(arr, arr[vertex].p)
	return arr[vertex].p

def function_of_union(arr,x,y):
    
	if arr[x].r > arr[y].r:
		arr[y].p = x
	elif arr[y].r> arr[x].r:
		arr[x].p = y
	else:
		arr[y].p = x
		arr[x].r += 1

						
graph = Graph_for_find_union(3)

graph.add_new_edge(0, 1)

graph.add_new_edge(1, 2)

graph.add_new_edge(0, 2)

if function_of_find_iscycle(graph):
	print('cycle is present in graph')
else:
	print('cycle is not present in graph"')

