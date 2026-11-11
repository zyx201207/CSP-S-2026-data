#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N],c[N],ans=1;
signed main(){
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,flag=1;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
	}//你好，我是XXX学校的XXX 
	if(n>=5000&&flag){
		if(a[2]-a[1]>m){
			cout<<1<<'\n';
		}
		else{
			int res=1;
			for(int i=1;i<=n;i++){
				b[i]=a[i]-a[i-1];
			}
			for(int i=2;i<=n;i++){
				c[i]+=b[i]+c[i-1];
			}
			int u=0;
			for(int i=1;i<=n;i++){
				u+=c[i];
				if(u>m)break;
				res=max(res,u);
			}
			cout<<res<<'\n';
		}
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int mid=a[i],res=1,v=m;
		for(int j=i-1;j>=1;j--){
			if(v>=mid-a[j]){
				v-=mid-a[j];
				res++;
			}
		}
		ans=max(res,ans);
		if(res==1){
			continue;
		}
	}
	cout<<ans<<'\n';
	return 0;
	
	
	
	
	/*
	我的思路：
	遍历数组a，选取ai作为平均值，用贪心看最多能改变几个数到达ai。 
	
	*/ 
}
