#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500005],t[500005],x[500005],ans[500005];
int tong[300005],chafen[500005],pre[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!tong[a[i]])tong[a[i]]=i;
		else{
			t[tong[a[i]]]=i;
			tong[a[i]]=i;
		}
		ans[i]=i;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+chafen[i];
		if(t[i]){
			chafen[i]-=(i+pre[i]);
			chafen[t[i]]+=(i+pre[i]);
		}
		pre[i]=pre[i-1]+chafen[i];
	}
	for(int i=1;i<=n;i++)ans[i]+=pre[i];
	for(int i=1;i<=n;i++){
		x[a[i]]=max(x[a[i]],ans[i]);
	}
	for(int i=1;i<=m;i++)cout<<x[i]<<' ';
	return 0;
}
