#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//类似字符串的双指针，如果次数不够左边动，然后右边动，计算差值 
	unsigned long long k=0;//差值 
	int ans=0;
	for(int i=1,j=1;i<=n,j<=n;j++){
		k+=(j-i)*(a[j]-a[j-1]);
		while(k>m&&i+1<=j){
			i++;
			k-=a[j]-a[i-1];
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
