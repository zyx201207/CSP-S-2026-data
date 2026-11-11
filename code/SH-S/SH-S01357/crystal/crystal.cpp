#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k;
int a[N],ans,cst,num,pre;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//cout<<"survive";
	cst=0;
	num=1,pre=1,ans=1;
	for(int i=2;i<=n;i++){
		cst+=(a[i]-a[i-1])*num;
		while(cst>k&&num){
			cst-=(a[i]-a[pre]);
			num--;
			pre++;
			//cout<<cst<<" "<<k<<endl;
		}
		if(num==0) pre=i;
		num++;
		
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
} 
