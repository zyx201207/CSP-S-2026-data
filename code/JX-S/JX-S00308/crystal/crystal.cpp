#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>ma;i--){
		long long zo=0,s=1;
		for(int j=i-1;j>=1;j--){
			zo=zo+a[i]-a[j];
			if(zo<=m){
				s++;
			}else{
				break;
			}
		}
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}
