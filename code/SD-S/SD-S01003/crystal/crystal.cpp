#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll s[500100];
ll a[500100];
ll b[500100];
ll n,m,n1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	n1=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n1+1,a[i])-b,s[a[i]]++;
	ll res=0,sum=0;
	for(int i=1,j=1;i<=n1;i++){
		ans=max(ans,res+s[i]);
		res+=s[i];
		sum+=res*(b[i+1]-b[i]);
		while(j<=i&&sum>m)sum-=(b[i+1]-b[j])*s[j],res-=s[j],j++;
		if(sum+(b[i+1]-b[j-1])<=m){
			ll cnt=0;
			while(cnt<s[j-1]&&sum+b[i+1]-b[j-1]<=m)sum+=b[i+1]-b[j-1],res++,cnt++;
			s[j-1]=cnt;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
