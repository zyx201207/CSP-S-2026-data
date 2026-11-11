#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,c,a[510005],b[510005];
bool check(int k){
	int s=a[k],cnt=0;
	for(int i=1;i<k;i++){
		cnt+=s-a[i];
		if(cnt>m)return 0;
	}
	return 1;
}
void go(){
	int r=1,l=n;
	while(r<=l){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid+1;
		}
		else{
			l=mid-1;
		}
	}
	cout<<l;	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])c=1;
	}
	if(c==0){
		go();
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			b[i]=b[i-1]+1;
			if(b[i]>ans)ans=b[i];
		}
		int cnt=0;
		for(int j=i-1;j>=1;j--){
			cnt+=a[i]-a[j];
			if(cnt<=m){
				if(i-j+1>ans){
					b[i]=i-j+1;
					ans=b[i];
				}
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}