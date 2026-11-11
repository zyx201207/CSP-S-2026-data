#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ma=0,ar[200005]={},pl[200005]={},flag1=1,flag2=1;
void dfs(int x,int li){
	if(x==m+1){
		int ans=pl[1];
		for(int i=2;i<=m;i++){
			ans&=pl[i];
		}
		ma=max(ma,ans);
		return;
	}
	for(int i=li+1;i<=n;i++){
		pl[x]=ar[i];
		dfs(x+1,i);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ar[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		int pf=ar[i]+1;
		if(flag1){
			while(pf){
				if(pf%2==0||pf==1){
					pf/=2;
				}else{
					flag1=0;
					break;
				}
			}
		}
		if(!(ar[i]==ar[i-1]+1)){
			flag2=0;
		}
	}
	if(n<=2000){
		dfs(1,0);
		cout<<ma;
	}else{
		if(flag1){
			int wz=n-m+1;
			sort(ar+1,ar+n+1);
			cout<<ar[wz]; 
		}else if(m==n-1&&n*n<=100000000){
			for(int i=1;i<=n;i++){
				int ans=0,flag=1;
				for(int j=1;j<=n;j++){
					if(j!=i){
						if(flag){
							ans=ar[i];
							flag=0;
						}else{
							ans&=ar[i];
						}
					}
				}
				ma=max(ma,ans);
			}
		}else{
			cout<<0;
		}
	}
	return 0;
}
