from collections import deque

def bfs(graph, start, goal):
    queue = deque([start])
    visited = {start}
    parent = {start: None}
    while queue:
        node = queue.popleft()
        if node == goal:
            path = []
            while node:
                path.append(node)
                node = parent[node]
            return path[::-1]
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)
                parent[neighbor] = node
    return None

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B'],
    'F': ['C']
}

bfs_result = bfs(graph, 'A', 'F')
print(bfs_result)
