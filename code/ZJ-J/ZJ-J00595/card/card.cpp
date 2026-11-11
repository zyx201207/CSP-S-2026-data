#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[500010],a[500010];
int ans[500010];
bool f[500010],ff[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500){
		for(int i=1;i<=n;i++){
			w[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<w[i]<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)ff[i]=0;
		for(int i=1;i<=m;i++)w[i]=0,f[i]=0;
		for(int i=k;i<=n;i++){
			if(w[a[i]]==0){
				w[a[i]]=i;
			}
			else{
				if(ff[w[a[i]]]==1){
					w[a[i]]=i;
				}
				else{
					for(int j=w[a[i]];j<i;j++)ff[j]=1;
					w[a[i]]=i;
				}
			}
		}
		for(int i=k;i<=n;i++){
			if(ff[i]==0){
				if(!f[a[i]])f[a[i]]=1,ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}