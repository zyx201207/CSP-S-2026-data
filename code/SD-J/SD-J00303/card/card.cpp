#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],vis[300010],n,m,sum[300010],ans[500010];
int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=i;j<=n;j++){
			ans[cnt]=a[j];
			if(vis[a[j]]!=0){
//				cout<<j<<endl;
				for(int k=vis[a[j]]+1;k<cnt;k++){
					vis[ans[k]]=0;
					ans[k]=0;
				}
				cnt=vis[a[j]];
			}else{
				vis[a[j]]=cnt;
			}
			cnt++;
		}
		for(int j=1;j<cnt;j++){
			vis[ans[j]]=0;
			sum[ans[j]]++;
//			cout<<ans[j]<<" ";
			ans[j]=0;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
