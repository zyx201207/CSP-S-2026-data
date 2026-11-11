#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NA=2e6+5;
int n,d;
int x[NA],w1[NA],w2[NA],pre[NA],suf[NA];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int c,t;
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			w1[i]=w2[i]=pre[i]=suf[i]=0;
		}
		int l=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[l]>d) l++;
			w1[i]=l;
		}
		int r=n;
		for(int i=n;i>=1;i--){
			while(x[r]-x[i]>d) r--;
			w2[i]=r;
		}
		for(int i=1;i<n;i++){
			if(w1[i]!=w1[i+1]){
				pre[i]=pre[w1[i]]+((w1[i+1]-1)-w1[i]+1);
			}
		}
		for(int i=n;i>=2;i--){
			if(w2[i]!=w2[i-1]){
				suf[i]=suf[w2[i]]+(w2[i]-(w2[i-1]+1)+1);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(w1[i]+2<=i){
				int j1=w1[i];
				int j2=w1[i]+1;
				int j3=w1[i]+2;
				int L=w1[j2];
				int R=w1[j3]-1;
				if(L<=R){
					int nump=(x[w1[j1]]>=x[L]?pre[L]:0);
					int nums=(x[i+1]-x[j2]>d?suf[i]:0);
					ans=ans+((R-L+1)+nump)*(nums+1);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
开考 180 分钟完成。 

齐芒保佑我思路正确！ 
*/ 
