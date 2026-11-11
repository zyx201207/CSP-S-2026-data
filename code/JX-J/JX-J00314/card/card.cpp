#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m;
int a[N];
int pre[N],nxt[N];
int _p[N],_n[N];
int main(){
    freopen("card2.in","r",stdin);
    freopen("card2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        // pre[i]=0;
        // nxt[i]=n+1;
        _p[i]=0;
        _n[i]=n+1;
    }
    for(int i=1;i<=n;i++){
        pre[i]=_p[a[i]];
        _p[a[i]]=i;
    }
    for(int i=n;i>=1;i--){
        nxt[i]=_n[a[i]];
        _n[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        int id=_p[i],ans=1;
		//cout<<i<<" "<<id<<"\n";
        int j=id-1,k=id;
        while(j>=1){
            if(nxt[j]==id&&nxt[j]!=n+1){
                k=j;
                // j--;
                // continue;
            }
            else if(nxt[j]>id&&nxt[j]!=n+1){
                j=pre[k];
                k=id=j;
            }
            if(j!=0)ans++;
            j--;
        }
        cout<<ans<<" ";
    }
    return 0;
}
