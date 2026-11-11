#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500010],t[500010],l,r,ans,b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		cout<<n;
		return 0; 
	}
	int i=1;
	while(i<=n){
		l=1,r=0;
		int f[300010]={0};
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				for(int k=f[a[j]]+1;k<=r;k++)f[b[k]]=0;
				r=f[a[j]];
			}else{
				r+=1;
				f[a[j]]=r;
				b[r]=a[j];
			}
		}
		for(;l<=r;l++)t[b[l]]++;
		i++;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
