#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=0;
void dfs(int x,int ans,int cnt){
	if(cnt>m){
		maxx=max(maxx,ans);
		return;
	}
	ans=(ans&a[x]);
	if(cnt==m-1) maxx=max(maxx,ans); 
	for(int j=1;j<=n-x;j++){
		dfs(x+j,ans,cnt+1);
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	int maxa=0,maxb=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(flag!=0&&a[i]+1!=2&&a[i]+1!=4&&a[i]+1!=8&&a[i]+1!=16&&a[i]+1!=32&&a[i]+1!=64&&a[i]+1!=128&&a[i]+1!=256&&a[i]+1!=512&&a[i]+1!=1024&&a[i]+1!=2048&&a[i]+1!=4096&&a[i]+1!=8192&&a[i]+1!=16384&&a[i]+1!=32768&&a[i]+1!=65536&&a[i]+1!=131072&&a[i]+1!=262144&&a[i]+1!=524288&&a[i]+1!=1048576&&a[i]+1!=2097152&&a[i]+1!=4194304&&a[i]+1!=8388608&&a[i]+1!=16777216&&a[i]+1!=33554432&&a[i]+1!=67108864&&a[i]+1!=134217728&&a[i]+1!=268435456&&a[i]+1!=536870912&&a[i]+1!=1073741824&&a[i]+1!=pow(2,31)){
			flag=0;
		}
	}
	if(flag==1){
		sort(a+1,a+1+n,cmp);
		int ans=a[1];
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,a[i],0);	
	}
	printf("%d",maxx);
	return 0;
} 
