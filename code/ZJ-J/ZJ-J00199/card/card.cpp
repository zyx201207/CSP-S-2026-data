#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,t,S[500010],s[500010],a[500010],b[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=n;i>=1;i--){
		if(S[a[i]]){
			for(j=S[a[i]]-1;j>i;j--)
				b[j]=max(b[j],i);
		}
		S[a[i]]=i;
	}
	ans[a[n]]=n;
	for(i=n-1;i>=1;i--){
		if(a[i]==a[n])continue;
		if(s[a[i]]==0||b[s[a[i]]]!=b[i])ans[a[i]]+=i-b[i]; 
		s[a[i]]=i;
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}