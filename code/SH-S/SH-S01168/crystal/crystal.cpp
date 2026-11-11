#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500010;
int n;
ll a[N],m,sum[N];
#define gc getchar
ll read_ll(){
	ll val = 0,w = 1;
	char c = gc();
	while(c<'0'||c>'9'){
		if(c=='-') w = -1;
		c = gc();
	}
	while('0'<=c&&c<='9'){
		val = val*10+c-'0';
		c = gc();
	}
	return val*w;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) a[i] = read_ll();
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i];
	int l = 1;
	int ans = 1;
	for(int i = 1;i <= n;i++){
		while((i-l+1)*a[i]-(sum[i]-sum[l-1])>m) l++;
		ans = max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	
} 
