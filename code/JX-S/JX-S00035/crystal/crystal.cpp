#include<bits/stdc++.h>
using namespace std;
long long a[500010];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int anss=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int ans=0;
		int k=m;
		for(int j=i;j>=1;j--){
			if(k>=a[i]-a[j]){
				k-=(a[i]-a[j]);
				ans++;
			}
			else{
				break;
			}
		}
		anss=max(ans,anss);
	}
	cout<<anss;
	return 0;
}
