#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
int n,m,ans=0,maxx=-1,b[N],a[N];
int main(){
    IOS;
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        for(int i=1;i<+n;i++)maxx=max(maxx,a[i]);
        cout<<maxx;
    }
    else if(m==2){
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)maxx=max(a[i]&a[j],maxx);
        cout<<maxx;
    }
    else if(m==n){
        maxx=a[1];
        for(int i=2;i<=n;i++)maxx=maxx&a[i];
        cout<<maxx;
    }
    else{
        int maxxx=-1;
        for(int xx=1;xx<=n/m;xx++){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j+=xx)b[++ans]=a[j];
                maxx=b[1];
                for(int j=2;j<=ans;j++)maxx=maxx&b[j];
                maxxx=max(maxx,maxxx);
            }
        }
        cout<<maxxx;
    }
    return 0;
}
