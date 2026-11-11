#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1])
		cnt+=a[i];
	}
	sort(a+1,a+1+n);
	int o=floor(cnt/n),f;
	for(int i=1;i<=n;i++){
		if(a[i]>o) {f=i-1;break;}
	}
	cout<<f;
	int now=0,ans=0;
	for(int i=f;i>=1;i--){
		if(now+a[f]-a[i]<=m){
			now+=(a[f]-a[i]);
			ans++;
		}
	}
	cout<<ans; 
	
	
	
	return 0;
} 
