#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int sum=0;
int mx=-1;
int aaa=-1;
int a[N],b[N];
bool st[N];
void dfs(int u,int start){
	if(u>m){
		int ss=0;
		for(int i=1;i<=m;i++){
			if(ss==0)	ss+=a[b[i]];
			else ss=ss&a[b[i]];
		}
		aaa=max(aaa,ss);
		return ;
	}
	if(start>n)	return ;
	for(int i=start;i<=n;i++){
		if(st[i])	continue;
		st[i]=true;
		b[u]=i;
		dfs(u+1,i+1);
		st[i]=false;
	}	
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		sum==0?sum=a[i]:sum=sum&a[i];
	}
	if(m==1){
		printf("%d",mx);
		return 0;
	}
	if(m==n){
		printf("%d",sum);
		return 0;
	}
	if(m==2){
		int xht=-1;
		for(int i=1;i<=n;i++){
			int mx0=-1;
			for(int j=i+1;j<=n;j++){
				mx0=max(mx0,a[i]&a[j]);
			}
			xht=max(mx0,xht);
		}
		cout<<xht;
		return 0;
	}
	dfs(1,1);
	printf("%d",aaa);
	return 0;
}
