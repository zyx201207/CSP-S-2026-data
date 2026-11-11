#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k=0,ans;
struct STU{
	int len;
	char x;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].len>>a[i].x;
	}
	int y=1,z=n;
	for(int i=1;i<=n&&y<z;++i){
		if(a[y].x!=a[z].x) ans+=min(a[y].len,a[z].len);
		if(a[y].len<a[z].len){
			a[z].len-=a[y].len;
			y++;
		}else{
			a[y].len-=a[z].len;
			z--;
		}
	}
	cout<<ans;
	return 0;
}
