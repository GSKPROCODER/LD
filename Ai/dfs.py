def dfs(graph, start, goal):
    stack = [start]
    visited = set()
    visited.add(start)
    parent = {start: None}

    while stack:
        node = stack.pop()
        if node == goal:
            path = []
            while node:
                path.append(node)
                node = parent[node]
            return path[::-1]

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = node
                stack.append(neighbor)
    return None
graph = {
    1:[2,3],
    2:[1,4],
    3:[1,5,6],
    4:[2],
    5:[3],
    6:[3]
}
start=1
goal=6
dfs_result = dfs(graph, start, goal)
print("DFS Path:", dfs_result)