#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
ll rd(){
	ll k=0;
	int f=1;
	char c;
	c=getchar_unlocked();
	while(c<'0'||c>'9'){
		if(c=='-')    f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar_unlocked();
	}
	return k*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)    a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		m-=i*(a[i+1]-a[i]);
		if(m<0){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<n<<'\n';
	return 0;
}
