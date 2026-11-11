#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1;
    for(int r=1;r<=n;r++){
        ll sum=s[r]-s[l-1];
        ll len=r-l+1;
        while(len*a[r]-sum>m){
            len--,l++;
            sum=s[r]-s[l-1];
        }
        ans=max(ans,len);
    }
    cout<<ans<<'\n';
	return 0;
}
