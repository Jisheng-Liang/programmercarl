#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count;
int dir[4][2] = {0,1,1,0,-1,0,0,-1};
int bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    queue<pair<int,int>> que;
    que.push({x,y});
    visited[x][y] = true;
    int area = 0;
    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][y];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
            if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){
                area += 1;
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }
    return area;
}

void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    if(visited[x][y] || grid[x][y] == 0) return; //有没有经过海水无所谓
    visited[x][y] = true;
    count++;
    for (int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
        dfs(grid, visited, nextx, nexty);
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                count = 0; // 因为dfs处理当前节点，所以遇到陆地计数为0，进dfs之后在开始从1计数
                dfs(grid, visited, i, j); // 将与其链接的陆地都标记上 true
                result = max(result, count);
            }
        }
    }
    cout << result << endl;
    return 0;
}