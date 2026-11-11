#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=500010,M=300010;
int n,m;
int a[N];
int mo[N],co[N];
int s[M];
bool rec[N];
stack<int> q;
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int tot=0;
    for(int i=1;i<=n;i++){
        memset(rec,0,sizeof(rec));
        for(int j=i;j<=n;j++){
            if(!rec[a[j]]) q.push(a[j]),rec[a[j]]=true;
            else{
                while(rec[a[j]]) rec[q.top()]=false,q.pop();
                rec[a[j]]=true;q.push(a[j]);
            }
        }
        while(q.size()) ans[q.top()]++,q.pop();
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}