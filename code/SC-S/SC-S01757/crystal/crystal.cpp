#include<bits/stdc++.h>
using namespace std;
int n,ans,zls=0;
long long m,cnt=0,sum,w;
long long a[500005];
long long c[500005];
bool cmp(int aaa,int bbb){
	return aaa<bbb;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	c[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(i-1)*(a[i]-a[i-1]);
		if(c[i]>m&&zls==0){
			ans=i-1;
			zls++;
		}
	}
	for(int i=2;i+ans<=n;i++){
		if(c[i+ans]-(i-1)*(a[i+ans]-a[i])-c[i]<=m){
			for(int j=i+ans;c[j]-(i-1)*(a[j]-a[i])-c[i]<=m;j++){
				if(j>n){
					break;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}