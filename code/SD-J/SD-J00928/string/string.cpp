#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,ans;
struct node{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	while(l<r){
		if(a[l].x==a[r].x){
			ans+=a[l].x*(a[l].c!=a[r].c);
			l++,r--;
		}
		else if(a[l].x<a[r].x){
			ans+=a[l].x*(a[l].c!=a[r].c);
			a[r].x-=a[l].x;
			l++;
		}
		else{
			ans+=a[r].x*(a[l].c!=a[r].c);
			a[l].x-=a[r].x;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
