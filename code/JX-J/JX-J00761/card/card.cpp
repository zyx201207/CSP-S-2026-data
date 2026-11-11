#include<bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,m;
int a[Maxn],b[Maxn],c[Maxn],hs[Maxn],ans[Maxn],sh[Maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		hs[a[i]]++;
		sh[a[i]]++;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]++;
				c[a[j]]=j;
			}
			else{
				for(int k=j;k<=j;k++){
					sh[a[k]]--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=sh[j];
		}
		for(int j=1;j<=m;j++){
			sh[j]=hs[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
