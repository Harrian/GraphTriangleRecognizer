#include <vector>
#include <set>
#include <algorithm>
std::set<std::vector<int>> findAllUnqiueTriangles(const std::vector<std::vector<bool>> & adj)
{
    std::set<std::vector<int>> triangles;
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj.size();j++)
        {
            if(i==j)
                continue;
            else if(adj[i][j])
            {
                for(int k=0;k<adj.size();k++)
                {
                    if(i==k||j==k)
                        continue;
                    else if(adj[j][k]&&adj[i][k])
                    {
                        std::vector<int> tmp{i,j,k};
                        std::sort(tmp.begin(),tmp.end());
                        triangles.emplace(tmp);
                    }
                }
            }
        }
    }
    return triangles;
}
