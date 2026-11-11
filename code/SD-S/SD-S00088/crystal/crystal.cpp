#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,a[N],m,ans;
__int128 sum[N];
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10)putchar(x+'0');
	else {
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		write(sum[i]);
//		cout<<'\n';
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;//Ã¶¾Ù[l,r] 
	for(r=1;r<=n;r++){
		int x=(r-l+1)*a[r]-(sum[r]-sum[l-1]);
		while(x>m){
			x-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
//		cout<<l<<' '<<r<<'\n'; 
	}
	cout<<ans<<'\n';
	return 0;
}

