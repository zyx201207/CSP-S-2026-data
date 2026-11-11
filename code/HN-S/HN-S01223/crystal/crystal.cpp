#include<bits/stdc++.h>
using namespace std;
const int W=5e5+5;
long long n,m,a[W],ans=1,sum,num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=a[1];
	num=1;
	for(int i=2;i<=n;i++){
		sum+=a[i];
		while(num<i&&1ll*a[i]*(i-num+1)-sum>m){
			sum-=a[num];
			num++;
		}
		ans=max(ans,i-num+1);
	}
	cout<<ans;
	return 0;
}
