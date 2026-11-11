#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n,m,cnt[N][32],st[N],mx,f[N];
LL a[N],ans;
bool cmp(LL a,LL b){
	return a>b;
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=31;j++){
			if(a[i]&(1<<j)) cnt[i][j]=1;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	init();
	for(int i=1;i<=n;i++){
		for(int j=31;j>=0;j--){
			if(cnt[i][j]==1) st[j]++;
		}
	}
	for(int i=31;i>=0;i--){
		if(st[i]>=m){
			mx=i;
			break;
		}
	}
	ans+=(1<<mx);
	for(int i=1;i<=n;i++){
		if(cnt[i][mx]) f[i]=1;
	}
	int t=mx;
	while(1){
		memset(st,0,sizeof(st));
		for(int i=1;i<=n;i++){
			for(int j=31;j>=0;j--){
				if(f[i]&&cnt[i][j]) st[j]++;
			}
		}
		for(int i=mx-1;i>=0;i--){
			if(st[i]>=m){
				mx=i;
				break;
			}
		}
		if(mx==t) break;
		for(int i=1;i<=n;i++){
			if(f[i]&&!cnt[i][mx]) f[i]=0;
		}
		t=mx;
		ans+=(1<<mx);
	}
	cout<<ans<<endl;
	return 0;
}
