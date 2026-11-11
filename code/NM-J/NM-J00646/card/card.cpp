#include<bits/stdc++.h>
using namespace std;
long long a[200001],f[200001],ff[200001],ans[200001],ii[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0,anss=0,maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
			if(a[i+1]!=maxx)ans[a[i]]+=i;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=0;
			ii[j]=0;
			ff[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=1){
				f[a[j]]=1;
				ans[a[j]]++;
				ii[a[j]]=j;
			}
			else{
				for(int k=ii[a[j]]+1;k<j;k++){
					f[a[k]]=0;
					if(ff[k]==0){
						ans[a[k]]--;
						
					}
					ff[k]=1;
					ff[j]=1;
				}
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
