#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300002];
bool vis[300003];
stack<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(m<=3000){
        for(int i=1;i<=n;i++){
                cin>>a[i];

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) vis[j]=false;
            for(int j=i;j<=n;j++){

                if(vis[a[j]]){
                    while(s.size()!=0 && s.top()!=a[j]){
                        s.pop();
                    }
                }
                else {
                        vis[a[j]]=true;
                        s.push(a[j]);

                }
            }
            while(s.size()!=0){
                ans[s.top()]++;

                s.pop();
            }

        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    }


    return 0;
}
