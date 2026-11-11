#include<iostream>
#include<fstream>
#include<cmath> 
#include<algorithm>
using namespace std;

int n,m,a[200005],f=1;
int ans;
void dfs(int id,int cnt,int val){
	if(id==n+1){
		if(cnt==m){
			ans=max(ans,val);
			return;
		}
		return;
	}
	if(cnt>m){
		return;
	}
	dfs(id+1,cnt+1,val&a[id]);
	dfs(id+1,cnt,val);
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(m==n){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
		return 0;
	}for(int i=1;i<=n;i++){
		if(!(log2(a[i]+1)==(int)log2(a[i]+1))){
			f=0;
			break;
		}
	}
	dfs(1,0,2147483647);
	 
	if(f==0){
	cout<<ans;	
	}else{
		sort(a+1,a+1+n,cmp);
		cout<<a[n-m+1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
