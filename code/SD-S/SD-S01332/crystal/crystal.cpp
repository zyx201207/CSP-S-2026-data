#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],n,m;
long long cnt[N];
void FCB(long long m){
	for(long long i=1;i<=n;i++){
		if(i*(i-1)/2>=m&&(i-1)*(i-2)/2<=m){
			cout<<i-1;
			return ;
		}
	}
	cout<<n;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool no114=0;
	bool CCF_is_what=0; 
	cin>>a[1];
	if(a[1]!=1)no114=1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)no114=1;	
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])CCF_is_what=1;
	}
	if(!no114){
		FCB(m);
		return 0;
	}
	if(!CCF_is_what){
		FCB(m/(a[2]-a[1]));
		return 0;
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		bool flag=0;
		long long now=0;
		for(int j=i-1;j>=1;j--){
			now+=(a[i]-a[j]);
			if(now>m){
				j++;
				ans=max(ans,1LL*i-j);
				flag=1;
				break;
			}
		}
		if(!flag)ans=max(ans,1LL*(i));
	}
	cout<<ans;
	return 0;
}
//一转定算法，一眼去暴力 看的全是那诡异代码 入得此场无需回首 OIER多秋，可怜诸神之黄昏 

