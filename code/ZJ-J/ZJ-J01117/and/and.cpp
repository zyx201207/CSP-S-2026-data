#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x[200005],fl,vis[200005];
int mx;
void calc(){
	int now;
	for(register int i=1;i<=m;i++){
		if(i==2){
			now=x[i]&x[i-1];
		}else if(i>2){
			now=now&x[i];
		}
	}
	mx=max(mx,now);
}
void dfs(int dep){
	if(dep==m+1){
		calc();
		return ;
	}
	for(register int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			x[dep]=a[i];
			dfs(dep+1);
			vis[i]=0;
		}
	}
	return ;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int anss;
	if(m==1){
		fl=1;
	}else if(m==n){
		fl=2;
	}
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(fl==1){
			mx=max(mx,a[i]);
		}
		if(fl==2){
			if(i==2){
				anss=a[i-1]&a[i];
			}else if(i>2){
				anss=anss&a[i];
			}
		}
	}
	if(fl==1){
		cout<<mx;
	}else if(fl==2){
		cout<<anss;
	}else if(m==2){
		mx=0;
		for(register int i=1;i<=n;i++){
			for(register int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else if(n<=20){
		mx=0;
		dfs(1);
		cout<<mx;
	}else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
