#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
int n,m,a[maxn],ans[maxn],cnt[maxn];
bool vis[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i],cnt[a[i]]++;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        if(a[n]==1) cout<<n<<" "<<cnt[2];
        else cout<<cnt[1]<<" "<<n;
        return 0;
    }
    if(n>500){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                cout<<i<<' ';
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        stack<int>mo;
        for(int j=i;j<=n;j++){
            stack<int>t;
            int f=1;
            while(!mo.empty()){
                int dick=mo.top();
                if(dick==a[j]){f=0;break;}
                else{
                    t.push(dick),mo.pop();
                }
            }
            if(f==1){
                while(!t.empty()) mo.push(t.top()),t.pop();
            }
            mo.push(a[j]);
        }
        for(int j=1;j<=m;j++) vis[j]=false;
        while(!mo.empty()){
            int dick=mo.top();
            vis[dick]=true;
            mo.pop();
        }
        for(int j=1;j<=m;j++) ans[j]+=(vis[j]?1:0);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
I often recall about the past.
*/
