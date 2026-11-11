#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
struct st{
	int num;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i].num>>a[i].c;
	int l=1,r=n;
	while(l<r){
		if(a[l].num<a[r].num){
			if(a[l].c!=a[r].c) ans+=a[l].num;
			a[r].num-=a[l].num;
			a[l].num=0;
			l++;
		}
		else if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c) ans+=a[r].num;
			a[l].num-=a[r].num;
			a[r].num=0;
			r--;
		}
		else{
			if(a[l].c!=a[r].c) ans+=a[r].num;
			a[l].num=0,a[r].num=0;
			l++,r--;
		}
	}
	cout<<ans;
}
