#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],s[N],cha[N],s1[N];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=-1;
	bool flagB=1;
	ll m,m1;
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		s1[i]=s[i-1]+i;
		if(i>=3&&a[i]-a[i-1]!=a[2]-a[1]){
			flagB=0;
		}
	}
	if(flagB){
		ll cha1=a[2]-a[1];
		for(int i=1;i<n;i++){
			if(m<(cha1*s[i])){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=a[1]+1;i<=a[n];i++){
		int id=-1;
		for(int j=1;a[j]<=i&&j<=n;j++){
			cha[j]=a[j]-i;
			id=j;
		}
		if(m+cha[id-1]<0){
			continue;
		}
		int cnt=0;
		for(int j=id-1;j>=1&&m1>=0;j--){
			m1+=cha[j];
			cnt++;
		}
		if(m1>=0){
			cnt++;
		}
		ans=max(ans,cnt);
		m1=m;
	}
	cout<<ans;
	return 0;
}
