#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define int long long
int res=1;
int n,m,h[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++){ 
		sum[i]=sum[i-1]+h[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=i-res;j>=1;j--){
			int nd=(i-j+1)*h[i]-(sum[i]-sum[j-1]);
			if(nd<=m){
				res=max(res,i-j+1);
			}else{
				break;
			}
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

