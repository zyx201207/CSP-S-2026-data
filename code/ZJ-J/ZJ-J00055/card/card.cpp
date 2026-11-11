#include<iostream>
using namespace std;
int a[500005],ans[500005],anss[500005],nxt[500005],lst[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)b[i]=0;
	for(int i=n;i>0;i--){
		lst[i]=b[a[i]];
		b[a[i]]=i;
	}
	//for(int i=1;i<=n;i++)cout<<nxt[i]<<" "<<lst[i]<<"\n";
	//for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	int jc=0,k=0;
	for(int i=n;i>0;i--){
		ans[a[i]]+=max(0,i-k);
		if(nxt[i]!=0)k=max(k,nxt[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
