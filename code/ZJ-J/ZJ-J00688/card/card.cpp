//Trick||Treat!
#include <bits/stdc++.h>
using namespace std;
int a[500005]={0},vis[300005]={0},num[300005]={0};
int s[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		int nn=1;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				s[nn++]=a[j];
				vis[a[j]]=1;
			}else{
				for(nn=nn-1;s[nn]!=a[j];nn--){
					vis[s[nn]]=0;
					s[nn]=0;
				}
				nn++;
			}
			//cout<<nn<<" ";
		}
		//cout<<" | ";
		for(int i=1;i<nn;i++){
			num[s[i]]++;
			//cout<<s[i]<<":"<<num[s[i]]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	return 0;
}
