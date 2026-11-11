#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
unsigned long long n,m,ans,tmp;
ll cry[MAXN],a[MAXN];

ll f(ll x){
	if(x<0)return (-1*x);
	else return x;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cry[i];
	sort(cry+1,cry+1+n);
	for(int i=1;i<=n;i++){
		a[i]=f(cry[i]-cry[(n+1)/2]);
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		if(tmp+a[i]<=m)tmp+=a[i];
		else break;
		ans++;
	}
	
	cout<<ans;
	
	return 0;
}
