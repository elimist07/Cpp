#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int, int>>> &paths, int src)
{
    // V=no of vertexes
    int V = paths.size();

    // min-heap priority-queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distance(V, INT_MAX);
    distance[src] = 0;  // distance of source to itself is obv zero
    pq.emplace(0, src); // distance,vertex
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop(); // pops out the first element ie the minimum

        // d=distance
        auto d = top.first;
        // u=source vertex
        auto u = top.second;
        // skip if d is not shortest
        if (d > distance[u])
            continue;
        // check all neighbouring vertex
        for (auto &p : paths[u])
        {
            // v=vertex
            int v = p.first;
            // w=weight
            int w = p.second;
            // short path found then update distance
            if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                pq.emplace(distance[v], v); // puts in first of queue
            }
        }
    }

    return distance;
}

int main()
{
    int src = 2;
    vector<vector<pair<int, int>>> paths(5);
    paths[0] = {{1, 4}, {2, 8}};
    paths[1] = {{0, 4}, {2, 3}, {4, 6}};
    paths[2] = {{0, 8}, {1, 3}, {3, 2}};
    paths[3] = {{2, 2}, {4, 10}};
    paths[4] = {{1, 6}, {3, 10}};

    vector<int> ans = dijkstra(paths, src);
    for (int d : ans)
        cout << d << endl;
    return 0;
}