#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+5;
ll a[maxn],b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int cnt1=0,cnt2=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		cnt1+=(a[i]==i?1:0); 
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]==a[i-1]-a[i-2]){
			cnt2++;
		} 
	}
	int ans=0;
	sort(a+1,a+n+1);
	if(m==0){
		int len=1;
		ll maxx=-1
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				len++;
			}else{
				len=0;
				maxx=max(maxx,len);
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(cnt1==n){
		for(int i=1;i*(i-1)/2<=m;i++){
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}else if(cnt2==n-2){
		ll sub=a[2]-a[1];
		if(m<sub){
			cout<<0<<endl;
			return 0;
		}
		for(int i=1;i*(i-1)/2<=m;i+=sub){
			ans++;
		}
		cout<<ans<<endl;
	}
	int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i-1;j>=1;j++){
			if(a[i]-a[j]<=m){
				cnt++;
			}
		}
		maxx=max(maxx,cnt+b[a[i]]);
	}
	cout<<maxx<<endl;
	return 0;
}
