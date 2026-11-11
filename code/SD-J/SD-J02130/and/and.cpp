#include<bits/stdc++.h>
using namespace std;
bool f[200010];
int n,m,ans=-1;
int a[200010];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int an,int st){
	if(x>m){
		ans=max(ans,an);
		return;
	}
	for(int i=st;i<=n;i++){
		if(f[i]==0&&(an&a[i])>ans){
			f[i]=1;
			dfs(x+1,an&a[i],i+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	dfs(1,pow(2,30)-1,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
