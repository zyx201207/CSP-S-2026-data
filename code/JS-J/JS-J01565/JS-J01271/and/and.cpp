#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N],s[N],mx=-1,mn,v[N],ans=-1;
void sol2(int dep){
    int y=mn;
    for(int i=1;i<=n;i++){
        if(!v[i]){
            int x=mn;
            mn=mn&a[i];
            if(dep==m){
                ans=max(ans,mn);
                mn=x;
                continue;
            }
            v[i]=1;
            sol2(dep+1);
            v[i]=0;
        }
    }
    mn=y;
    return;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++)
        s[i]=s[i-1]&a[i];
    if(m==n){
        cout<<s[n];
        return 0;
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==2){
        mn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mn=max(mn,a[i]&a[j]);
            }
        }
        cout<<mn;
        return 0;
    }
    if(n<=20){
        mn=a[1];
        sol2(1);
        cout<<ans;
        return 0;
    }
    return 0;
}
