#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool putt[500010];
int cnt[300010];
stack<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=m;k++){
        for(int i=k;i<=n;i++){
            if(putt[a[i]]==0){
                q.push(a[i]);
                putt[a[i]]=1;
            }else{
                while(q.top()!=a[i]){
                    q.pop();
                }
                q.pop();
                q.push(a[i]);
            }
        }
        while(!q.empty()){
            int lol=q.top();
            cnt[lol]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
