#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],f[500001],ans[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i!=n)fl&=(a[i]<=a[i+1]);
		s[i]=f[a[i]]+1;
	}
	if(!fl){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j=s[j])ans[a[j]]++;
		}
	}else{
		for(int i=1;i<=n;i++)ans[i]=f[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
