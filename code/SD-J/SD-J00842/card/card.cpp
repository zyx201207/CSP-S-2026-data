#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lastnum[300005];
int ans[300005];
int stk[500005],top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		top=0;
		memset(lastnum,0,sizeof lastnum);
		for(int j=i;j<=n;j++){
			if(!lastnum[a[j]]) stk[++top]=a[j],lastnum[a[j]]=top;
			else{
				stk[++top]=a[j];
				int pos=top,tim=lastnum[a[j]];
				for(int k=1;k<=pos-tim;k++){
					lastnum[stk[top]]=0;
					top--;
				}
				lastnum[a[j]]=top;
			}
		}
		while(top){
			ans[stk[top]]++;
			//app[stk[top]].push_back(i);
			//cout<<stk[top]<<" ";
			top--;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	/*cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)app[i].size();j++)
			cout<<app[i][j]<<" ";
		cout<<endl;
	}*/
	return 0;
}
