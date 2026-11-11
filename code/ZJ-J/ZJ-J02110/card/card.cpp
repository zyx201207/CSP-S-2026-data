#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],p[500005],q;
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int>mp;
		q=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==1){
				int vis=0,op=q;
				for(int k=1;k<=op;k++){
					if(vis==1)mp[p[k]]=0;
					if(p[k]==a[j]){
						q=k;
						vis=1;
					}
				}
			}
			else{
				q++;
				p[q]=a[j];
				mp[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=mp[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
