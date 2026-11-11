#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 3e5+10;
int order[N];
long long cnt[M];
bool visit[M];
stack<int> table;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>order[i];
    for(int i = 1;i<=n;i++) {
        memset(visit,0,sizeof(visit));
        if(order[i] == order[n]){
            cnt[order[i]]++;
            continue;
        }
        for(int j = i;j<=n;j++){
            if(visit[order[j]] == 0){
                table.push(order[j]);
                visit[order[j]] = 1;
            }else{
                while(table.top()!=order[j]){
                    visit[table.top()] = 0;
                    table.pop();
                }
                table.pop();
                table.push(order[j]);
            }
        }
        while(!table.empty()){
            cnt[table.top()]++;
            table.pop();
        }
    }
    for(int i = 1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
