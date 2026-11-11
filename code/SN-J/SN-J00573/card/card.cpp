#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],cnt[N],vis[N],sta[N],top;
void work(int x){
	memset(vis,0,sizeof(vis));
	memset(sta,0,sizeof(sta));
	top=0;
	for(int i=x;i<=n;i++){
		while(sta[top]!=a[i]&&vis[a[i]]){
			vis[sta[top--]]=0;
		}
		vis[a[i]]=1;
		if(sta[top]!=a[i]) sta[++top]=a[i];
	}
	for(int i=1;i<=m;i++){
		if(vis[i]) cnt[i]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f&&n>5000){
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]) cnt[a[i]]=i;
		}
	}else{
		for(int i=1;i<=n;i++){
		    work(i);
	    }
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
