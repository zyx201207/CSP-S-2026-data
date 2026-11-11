#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans,lt,rt,a[N];
char c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	lt=1;rt=n;
	while(lt<rt){
		if(c[lt]!=c[rt]){
			ans=ans+min(a[lt],a[rt]);
			if(a[lt]>a[rt]) a[lt]-=a[rt],rt--;
			else if(a[lt]<a[rt]) a[rt]-=a[lt],lt++;
			else lt++,rt--;
		}
		else{
			if(a[lt]>a[rt]) a[lt]-=a[rt],rt--;
			else if(a[lt]<a[rt]) a[rt]-=a[lt],lt++;
			else lt++,rt--;
		}
	}
	cout<<ans;
	return 0;
}
