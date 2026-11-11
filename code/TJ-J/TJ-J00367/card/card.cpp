#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10],c[10],ans[10],b[10];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		int t=i;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=1){
				c[t++]=a[j];
				b[a[j]]=1;
			}
			else{
				while(c[t]!=a[j])c[t--]=0;
				c[t]=0;
				b[a[j]]=0;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
