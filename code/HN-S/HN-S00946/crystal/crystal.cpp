#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500100;
int ans,a[N],dp[N],pos;
int l,r,mid,n,m,k,mat=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int t=1;t<=n;t++){
		int i=a[t];
		while(a[t]==a[t+1]&&t<n) t++;
		int sum_a=0,mul=0;
		for(int j=t;j>=1;j--){
			mul=mul+(i-a[j]);
			if(mul<=m) sum_a++;
			else break;
		}
//		cout<<i<<" "<<sum_a<<" "<<pos<<endl;
		mat=max(mat,sum_a);
	}
	cout<<mat;
	return 0;
}
