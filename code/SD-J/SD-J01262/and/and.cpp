#include<bits/stdc++.h> 
using namespace std;
long long n,m,r=0,l=0,ans;
string s1,s2,s3,s4;
long long a[200010],f[10001][10001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
}
