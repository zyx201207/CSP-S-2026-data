#include"bits/stdc++.h"
using namespace std;
int n,m;
int a[500010];
bool vis[300010];
int ans[500010];
stack<int>de;
//int read(){’®¡À£°£°£° 
//	int f=1;
//	int shu=0;
//	char tmp;
//	while(tmp<'0' && tmp>'9'){
//		tmp=getchar();
//		if(tmp=='-') f=-1;
//	}while('0'<=tmp && tmp<='9'){
//		tmp=getchar();
//		if(shu=0){
//			shu+=tmp-'0';
//		}else{
//			shu*=10;
//			shu+=tmp-'0';
//		}
//	}
//	return f*shu;
//}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(de.top()!=a[j]){
					int qi=de.top();
					de.pop();
					vis[qi]=0;
				}
			}else{
				de.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!de.empty()){
			int zai=de.top();
			de.pop();
			ans[zai]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
