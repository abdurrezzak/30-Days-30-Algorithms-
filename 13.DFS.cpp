/*
 * This program applies DFS on a graph constructed from the inputs of the user
 *
 *      Coded by: Abdurrezak EFE
 *
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class Graph{

    vector<vector<int>> edge;
    vector<int> color; // 0 black(finished node), 1 white(neither visited nor finished node)

public:

    Graph(int v)
    {
        edge.resize(v);
        color.resize(v);
        for(int i=0;i<v;i++) //initializing nodes' colors
            color[i] = 1;
    }

    void add_edge(int v, int u)
    {
        //adding from both directions makes it undirected
        edge[v].push_back(u);
        edge[u].push_back(v);
    }

    void DFS(int s) //dfs operation
    {
        if(!color[s])
            return;

        stack<int> st;
        st.push(s);

        while(!st.empty())
        {
            s = st.top();
            if(color[s] == 0)
                continue;
            color[s] = 0, cout << s+1 <<  " ";
            st.pop();
            for(int i=0;i<edge[s].size();i++)
                if(color[edge[s][i]] == 1)
                    st.push(edge[s][i]);
        }
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices you want to add" << endl;
    cin >> v;

    int e;
    cout << "Enter the number of edges you want to add" << endl;
    cin >> e;

    Graph g(v);

    cout << "Enter the edges" << endl;
    int u,w;
    for(int i=0;i<e;i++)
        cin >> u >> w, g.add_edge(u,w);


    for(int i=0;i<v;i++) //this for prevents our dfs from not traversing on non-connected parts
        g.DFS(i); //starting DFS from vertex i
}