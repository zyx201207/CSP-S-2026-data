//T3 and 解法1 预期75
//Trick||Treat!
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],maxn=-1,ans;
int fs(int x,int sum,int start){
	if(x==m) return sum;
	int Maxn=-1;
	for(int i=start;i<=n;i++){
		Maxn=max(Maxn,fs(x+1,sum&a[i],i+1));
	}
	return Maxn;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){//第6个点
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}else if(m==2){//第8到10个点
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
		}
		cout<<maxn;
		return 0;
	}else if(m==n){//第7个点
		ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	bool f4=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			f4=0;
			break;
		}
	}
	if(f4){//第14到15个点
		cout<<n-m;
		return 0;
	}else if(n<21){//第1到5个点
		cout<<fs(0,2147483647,1);
		return 0;
	}
	bool f6=1;
	for(int i=1;i<=n;i++){
		if(a[i]>3){
			f6=0;
			break;
		}
	}
	if(f6){//第16到17个点
		int sum0=0,sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) sum0++;
			else if(a[i]==1) sum1++;
			else if(a[i]==2) sum2++;
			else if(a[i]==3) sum3++;
		}
		if(sum3>=m) cout<<3;
		else if(sum2+sum3>=m) cout<<2;
		else if(sum1+sum3>=m) cout<<1;
		else if(sum0>=m) cout<<0;
		return 0;
	}else{//第13个点
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
}