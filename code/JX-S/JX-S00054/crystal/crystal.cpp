#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=500005;
int n,m;
int a[N];
int ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int p1=1;
    int p2=1;
    int weight=0;
    while(p1<=n&&p2<=n&&p1<=p2){
        while(weight>m){
            weight-=a[p2]-a[p1];
            p1++;
            
        }
        ans=max(ans,p2-p1+1);
        weight+=1LL*(p2-p1+1)*(a[p2+1]-a[p2]);
        p2++;
    }
    cout<<ans;
}