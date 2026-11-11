#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n,l,r=1;
int ans;
ll m;
ll a[maxn];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
while(l<=r&&r<n){
        if(m>=0) {
                m-=((a[r]-a[r-1])*(r-l));
                 ans=max(ans,(r-l));
    r++;
        }
        else {
        m+=(a[r-1]-a[l]);
        l++;
        continue;
    }
ans=max(ans,(r-l-1));
}
cout<<ans;
return 0;
}
