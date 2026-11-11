#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],res=1;
int main(){
//	freopen("E:/down/crystal/crystal4.in","r",stdin);
//	freopen("E:/down/crystal/crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,sum=0;
	for(int r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		res=max(res,r-l+1);
	}
	cout<<res;
	return 0;
}