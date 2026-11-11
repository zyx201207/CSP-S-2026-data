#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=200010;
int n,m;
int a[N];
bool b[N];
int ans=0,k=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=29;i>=0;i--){
        k=0;
        for(int j=1;j<=n;j++){
            if(b[j])continue;
            k+=(a[j]>>i)&1;
        }
        if(k<m) continue;
        for(int j=1;j<=n;j++){
            if(b[j])continue;
            if(((a[j]>>i)&1)==0) b[j]=true;
        }
        ans+=1<<i;
    }
    cout<<ans;
    return 0;
}