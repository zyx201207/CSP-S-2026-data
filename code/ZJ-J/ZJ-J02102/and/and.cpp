#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],Max=-1;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int t,int v){
	if(t==m+1){
		Max=max(Max,v);
		return ;
	}
	for(int i=t;i<=n;i++){
		if(a[i]<=Max) return;
		v= v & a[i];
		dfs(t+1,v);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==n){
		int v=a[1];
		for(int i=2;i<=n;i++){
			v= v & a[i];
		}
		cout<<v;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				Max=max(Max,a[i] & a[j]);
			}
		}
		cout<< Max;
		return 0;
	}else if(m==n-1){
		int v=a[1];
		for(int i=2;i<=n-1;i++){
			v= v & a[i];
		}
		cout<<v;
		return 0;
	}else if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(2,a[i]);
		}
		cout<<Max;
		return 0;
	}else{
		int f1=1,f2=1;
		for(int i=1;i<=100;i++){
			int t=a[i];
			for(int j=1;j<=21;j++){
				int t1=pow(2,j);
				if(t1!=t+1) f1=0;
				
			}
			if(a[i]!=i-1) f2=0;
		}
		if(f1){
			int v=a[1];
			for(int i=2;i<=m;i++){
				v= v & a[i];
			}
			cout<<v;
			return 0;
		}else if(f2){
			int v=a[1];
			for(int i=2;i<=m;i++){
				v= v & a[i];
			}
			cout<<v;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	return 0;
}