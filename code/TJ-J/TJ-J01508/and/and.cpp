#include<bits/stdc++.h>

using namespace std;
//cout << (kskbl ? zdjd : wkk);
//不要交in,out文件 要交且仅交cpp源文件。
int a[200005];
int n,m,ans=-0x3fffff;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int k,int sum,int x){
	if(k>n) {
		return;
	}
	if(x==0) {
		ans=max(sum,ans);
		return;
	}
	dfs(k+1,sum&a[k],x-1);
	dfs(k+1,sum,x);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(1,a[1],m);
//	
//	for(int i=1;i<=m;i++) ans&=a[i];
	cout<<ans;
	//25
	return 0;
}

