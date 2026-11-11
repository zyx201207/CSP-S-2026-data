#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],p[300010],f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		memset(p,0,sizeof p);
		for(int k=i;k<=n;k++){
			if(p[a[k]]!=0&&f[p[a[k]]]==0){
				//cout<<91;
				for(int j=p[a[k]];j<k;j++){
					f[j]=1;
					//cout<<'a';
				}	
			}
			p[a[k]]=k;
		}
		for(int j=i;j<=n;j++){
			if(f[j]==0){
				ans[a[j]]++;
				//cout<<a[j]<<' ';
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
