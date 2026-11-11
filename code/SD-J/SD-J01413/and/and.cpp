#include<bits/stdc++.h>
using namespace std;
int a[200010],n,c,u[200010],ma=-1,an=2e31-1,flag[200010];
void dfs(int h){
	if(h==c+1){
		an=2e31-1;
		for(int i=1;i<=c;i++){
			an=an&u[i];
		}
		ma=max(ma,an);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<u[h-1]){
			continue;
		}
		if(flag[i]==1){
			continue;
		}
		flag[i]=1;
		u[h]=a[i];
		dfs(h+1);
		u[h]=0;
		flag[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int an=2e31-1;
	ma=-1;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		an=an&a[i];
	}
	sort(a+1,a+1+n);
	if(c>=n){
		cout<<an;
	}
	else if(c==1){
		cout<<ma;
	}
	else if(c==2){
		ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}
	else{
		ma=-1;
		an=2e31-1;
		dfs(1);
		cout<<ma;
	}
	return 0;
}
