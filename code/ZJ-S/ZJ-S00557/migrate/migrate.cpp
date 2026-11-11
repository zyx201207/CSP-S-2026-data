#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N=2e6+5;
int a[N];
int n,d;
bool cheak1(){
	int cha=a[2]-a[1];
	bool flag=1;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=cha){
			flag=0;
			break;
		}
	}
	if(flag){
		if(d<cha*2) cout<<0<<"\n";
		else cout<<max(n-(d/cha-1)*2-1,0ll)<<"\n";
		return 1;
	}
	return 0;
}
bool cheak2(){
	bool flag=0;
	int cnt=0;
	for(int i=1;i<=n;i++) if(a[i]-a[1]<=d&&a[n]-a[i]<=d) flag=1,cnt=i;
	if(flag){
		cout<<0<<"\n";
		return 1;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(cheak1()) continue;
		if(cheak2()) continue;
//		if(cheak3()) continue;
		cout<<0<<"\n";
	}
	return 0;
}