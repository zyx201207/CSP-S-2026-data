#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,js,p,t,pai[500010],a[500010],ans[300010],jump,bao[300010],qb[500010],jl[300010],s=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=500&&m<=200){
		for(js=1;js<=n;js++){
			for(i=1;i<=t;i++) pai[i]=0;
			t=0;
			for(i=js;i<=n;i++){
				for(p=1;p<=t;p++){
					if(pai[p]==a[i]){
						t=p-1;break;
					}
				}
				pai[++t]=a[i];
			}
			for(p=1;p<=t;p++) ans[pai[p]]++;
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(i=n;i>=js;i--){
		qb[i]=bao[a[i]];
		bao[a[i]]=i;
	}
	if(n<=5000&&m<=3000){
		for(js=1;js<=n;js++){
			i=js;
			while(i<=n){
				jl[a[i]]=1;
				jump=qb[i];
				if(jump==0) i++;
				else i=jump;
			}
			for(i=1;i<=m;i++)  
				if(jl[i]==1) ans[i]++,jl[i]=0;
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(m==1){cout<<n;return 0;}
	if(m==2){
		for(js=1;js<=n;js++){
			if(a[js]==a[n]) ans[a[n]]++;
			else ans[a[n]]++,ans[a[js]]++;
		}
		for(i=1;i<=2;i++) cout<<ans[i]<<" ";
		return 0;
	}
	a[n+1]=0;
	for(i=1;i<n;i++)
		if(a[i]<=a[i+1]) s++;
	if(s==n-1){
		for(i=2;i<=n+1;i++)
			if(a[i]!=a[i-1]) ans[a[i-1]]=i-1;
		for(i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	return 0;
}

