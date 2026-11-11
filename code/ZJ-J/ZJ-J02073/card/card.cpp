#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int a[N];
int pre[N],pos[N],sk[N],top;
int n,m,vis[N],ans[N],nxt[N];
int diff[N];
int read(){
	int k=0,c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())k=k*10+(c^48);
	return k;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();//cout<<n;
	for(int i=1;i<=n;i++){
		//scanf("%d",&a[i]);
		a[i]=read();
	}
	for(int i=n;i;i--){
		if(pos[a[i]]){
			pre[i]=pos[a[i]];
		}
		else pos[a[i]]=i;
	//	cout<<i<<' '<<pos[a[i]]<<' '<<pre[i]<<endl;
	}
	pre[n]=n+1;
	int pos=n;
	for(int i=n;i;i--){
		if(pre[i]){
			pos=i;
		}else{
			nxt[i]=pos;
		}
	}
	for(int i=1;i<=n;i++){
		int p=i;
		while(p<=n){
			//cout<<p<<' ';
			if(pre[p]){
			ans[a[p]]++;
				p=pre[p];
			//	if(vis[p]!=i){
				p++;
				//	vis[p]=i;
			//	}
			}else{
			//	if(vis[p]!=i){
					//ans[a[p]]++;
				//	vis[p]=i;
			//	}
			diff[p]++;
			diff[nxt[p]]--;
				p=nxt[p];
			}
		}//cout<<endl;
	}
	int bhc=0;
	for(int i=1;i<=n;i++){
		bhc+=diff[i];
		ans[a[i]]+=bhc;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}