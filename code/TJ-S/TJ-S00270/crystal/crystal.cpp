#include<bits/stdc++.h>
using namespace std;

unsigned long long n,m,a[500005],midd,ans;
unsigned long long cnt,sum;
const int N=1e5;
bool flag=1;

void solve(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) flag=0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cnt=0;
		for(int j=i;j>=1;j--){
			cnt=cnt+a[i]-a[j];
		}
		if(cnt<=m){
			if(flag) cout<<i;
			else cout<<i*2;
			break;
		}
	}
}
void solve1e8(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		vis[a[i]]++;
		
	}
	sort(a+1,a+n+1);
//	sort(vis,vis+N);
//	cnt=vis[N];
//	midd=a[(n+1)/2];
	for(int i=1;i<=n;i++){
		if(abs(a[i]*i)<=m) cnt=i,midd=a[i];
	}
	for(int i=cnt; ;i++){
		if(a[i]==midd) ans++;
		else break;
	}
	cout<<cnt+ans<<endl;
//	cout<<(n+1)/2+ans<<endl;
//	for(int i=(n+1)/2-1;i>=1;i--){
//		if(m-(midd-a[i])<0) break;
//		m=m-(midd-a[i]);
//		ans++;
//	}
//	cout<<max(ans+1,cnt);
	exit(0);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin>>n>>m;
	solve1e8();
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	midd=a[(n+1)/2];
//	for(int i=(n+1)/2; ;i++){
//		if(a[i]==midd) ans++;
//		else break;
//	}
//	for(int i=(n+1)/2-1;i>=1;i--){
//		if(m-(midd-a[i])<0) break;
//		m=m-(midd-a[i]);
//		ans++;
//	}
//	cout<<ans;
//	
	return 0;
} 
