#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001],pre[300001];
int last[300001];
inline int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int jump(int x){
	int en=x;
	if(pre[x]!=-1){
		en=jump(pre[x]);
	}
	return en;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	memset(last,0,sizeof(last));
	for(int i=n;i>=1;i--){
		if(last[a[i]]==0){
			last[a[i]]=i;
			pre[i]=-1;
		}else{
			pre[i]=last[a[i]];
			last[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pre[j]!=-1){
				ans[a[j]]++;
				j=jump(j);
			}else{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
