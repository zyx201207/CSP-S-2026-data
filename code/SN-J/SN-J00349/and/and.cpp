#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	int n,m,ans;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m+1;i++)
		ans=ans&a[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
