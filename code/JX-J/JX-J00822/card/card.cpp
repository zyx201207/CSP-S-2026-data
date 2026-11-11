#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],s[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int pd=0;
			for(int k=1;k<j;k++){
				if(c[k]==s[j]){
					for(int v=k+1;v<=n;v++){
						c[v]==0;
					}
					pd=1;
					break;
				}
			}
			if(pd==0){
				for(int k=1;k<=n;k++){
					if(c[k]==0){
						c[k]=s[j];
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[c[j]]++;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}