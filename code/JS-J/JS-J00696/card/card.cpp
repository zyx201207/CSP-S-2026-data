#include<bits/stdc++.h>
#define ll long long
#define atn 522222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[atn],n,m,ans[atn],lst[atn];
bool b[atn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    f(i,1,n)cin>>a[i];
    for(int i=n;i>=1;--i){
        if(lst[a[i]]==0)lst[a[i]]=i;
    }
    f(i,1,n){
        f(j,1,m)b[j]=0;
        f(j,i,n){
            if(j!=lst[a[j]]){
                j=lst[a[j]];b[a[j]]=1;
            }else{
                b[a[j]]=1;
            }
        }
        f(j,1,m)if(b[j]==1)ans[j]++;
    }
    f(i,1,m)cout<<ans[i]<<' ';
    return 0;
}
