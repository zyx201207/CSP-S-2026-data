#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, n, m, th, time;//样例判断，线路数量，站台数量，最多被穿过的地铁数量，测试个数
    vector<int> w(m + 1);//从地铁口走到站厅
    for(int i = 1;i <= m; i++){
        cin >> w[i];
    }
    vector<int> a[n + 1];//i号线穿过的站台
    vector<int> k(n + 1);//穿过的站台数量
    int t[m+1][n+1];//t[i][j]表示从i号站厅走到站台的时间
    for(int i = 1;i <= n; i++){
        cin >> k[i];
        for(int j = 1;j <= k[i]; j++){
            cin >> a[i][j];
            cin >> t[a[i][j]][i];
        }
    }
    while( time-- ){
        vector<int> route;
        route.push_back(0);
        int sta, fin;
        cin >> sta >> fin;
        for(int i = 1;i <= n; i++){
            for(int x : a[i]){
                if(x == sta){
                    route.push_back(i);
                    break;
                }
            }
        }
        for(int i = 1;i <= n; i++){
            for(int x : a[i]){
                if(x == fin){
                    route.push_back(i);
                    break;
                }
            }
        }
        //寻找route里面交叉的节点
        int l = route.size();
        vector<int> tong(m, 0);
        for(int i = 1;i <= l; i++){
            for(auto x : a[route[i]]){
                tong[x]++;
            }
        }
        int l2 = tong.size();
        for(int i = 1;i <= l2; i++){
            if(tong[i] == 2){
                cout << w[sta] + t[sta][1] + t[i][1] + t[i][2] + t[fin][2] + w[fin] << '\n';
                break;
            }
        }
    }
    return 0;
}
