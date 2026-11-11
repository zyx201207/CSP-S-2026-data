#include <bits/stdc++.h>
using namespace std;
long long a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	int n;
	long long m,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int j=i-1;
		long long k=0,ans1=1;
		do{
			k+=(a[i]-a[j]);
			if(k<=m) ans1++;
			j--;
		}while(k<=m&&j>0);
		if(ans1>ans){
			ans=ans1;
		}
	}
	cout<<ans;
	return 0;
}
