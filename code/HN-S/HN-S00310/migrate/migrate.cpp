#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],cnt,n1=2e18;
int dfs(int l,int r,int k1){
	if(l==r){
		if(k1<n1){
			n1=k1;
			cnt=1;
		}else{
			if(k1==n1){
				cnt++;
			}
		}
		return 0;
	}
	if(k1>=n1){
		return 0;
	}
	for(int i=r-l;i>=1;i--){
		if(a[l+i]-a[l]<=d){
			dfs(l+i,r,++k1);
			k1--;
		}
	}
	if(cnt==2){
		return 1;
	}else{
		return 0;
	}
}
int judge(int l,int r){
	cnt=0;
	n1=2e18;
	if(dfs(l,r,0)){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ans+=judge(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//用我师兄十年单生+寿命换我今年s 1=
//不然我就要AFO了 
