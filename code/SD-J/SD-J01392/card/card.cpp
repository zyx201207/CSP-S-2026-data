#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],nxt[N]={0},ans[M]={0};
map<int,int> f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=m;i++){
		ans[i]=0;
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int j = n;j>=1;j--){
		f[a[j]]=max(f[a[j]],j);
	}
	for(int j = 1;j<=n;j++){
		if(f[a[j]]==j){
			nxt[j]=j+1;
		}else{
			nxt[j]=f[a[j]]+1;
		}
	//	cout<<nxt[j]<<" ";
	}//cout<<endl;
	for(int j = n;j>=1;j--){
		for(int i = n-j+1;i&&i<=n;i=nxt[i]){
		//	cout<<ans[a[i]]<<" ";
			ans[a[i]]++;
		}//cout<<endl;
	}
	for(int i = 1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
