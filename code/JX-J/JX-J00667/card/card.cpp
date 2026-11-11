#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
int n,m,a[maxn],f[maxn],b[maxn];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> s;
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                while(!s.empty()&&s.top()!=a[j]){
                    f[s.top()]=0;
                    b[s.top()]--;
                    s.pop();
                }
            }else{
                f[a[j]]=1;
                s.push(a[j]);
                b[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
