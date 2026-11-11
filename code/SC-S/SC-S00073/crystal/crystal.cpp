#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+50;
int a[maxn];
long long diff[maxn];
long long pre[maxn]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}
	pre[1]=0;
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+diff[i];
	}
	int l=1,r=1;
	int cnt=0;
	int ans=1;
	int maxx=0;
	while(r<=n){
		r++;
		if(r>n){
			break;
		}
		cnt+=diff[r]*1ll*ans;
		ans++;
		if(cnt>m){
			ans--;
			cnt-=(pre[r]-pre[l]);
			l++;
		}
		else if(m>=cnt){
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
}