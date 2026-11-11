#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5,M=3e5+5;
int a[N];
int c[N];
int ans[M];
int la[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1])f=1;
	}
	if(!f){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}else if(m<=2){
		ans[a[n]]=n;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n])ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}else{
		for(int i=1;i<=n;i++){
			memset(la,0,sizeof la);
			memset(c,0,sizeof c);
			for(int j=i;j<=n;j++){
				if(la[a[j]]==0){
					la[a[j]]=j;
				}else{
					for(int k=la[a[j]];k<j;k++){
						c[k]=1;
						la[a[k]]=0;
					}
					la[a[j]]=j;
				}
			}
			for(int j=i;j<=n;j++){
				if(!c[j])ans[a[j]]++;
			}
//			for(int j=1;j<=m;j++){
//				cout<<ans[j]<<' ';
//			}
//			cout<<'\n';
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
