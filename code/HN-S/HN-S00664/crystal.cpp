#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0,m;
int n,y;
int x[100005],a[100005];
void quick(int lu,int midn,int ru){
    if(a[midn]<a[lu]){
        swap(a[midn],a[lu]);
        midn--;
        quick(lu,midn,ru);
    }
    if(a[midn]>a[ru]){
        swap(a[midn],a[ru]);
        midn++;
        quick(lu,midn,ru);
    }

}
void cat(ll a,ll b,int c){
if(ans<=m){
    ans=ans+a*c;
}
}



int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n>>m;
 for(int i=1;i<=n;i++)
    cin>>a[i];
ll l=1;
ll r=n;
ll mid=(l+r)/2;
quick(l,mid,r);
for(int i=1;i<=n;i++){
    x[i]=a[i+1]-a[i];
}
for(int i=1;i<=n;i++){
    cat(x[i],x[i+1],i);
}
cout<<ans;
}


