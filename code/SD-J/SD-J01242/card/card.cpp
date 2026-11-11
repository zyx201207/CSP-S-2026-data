#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],nxt[500005],ans1[500005];
string ans[500005],s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]='0';
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(i!=n)for(int j=1;j<=m;j++)ans[i][j]=ans[i+1][j];
		if(nxt[a[i]]==0){
			nxt[a[i]]=i;		
			ans[i][a[i]]+=1;
		}
		else{
			for(int j=1;j<=m;j++)ans[i][j]=ans[nxt[a[i]]][j];
			nxt[a[i]]=i;
		}
	}
	for(int j=1;j<=m;j++){
		int op=0;
		for(int k=1;k<=n;k++){
			op+=ans[k][j]-48;
		}
		cout<<op<<" ";
	}
//	for(int i=1;i<=m;i++){
//		int ans11=0;
//		for(int j=1;j<=n;j++){
//			ans11+=ans[i][j]-48;
//		}
//		cout<<ans11<<endl;
//	}
	return 0;
}

