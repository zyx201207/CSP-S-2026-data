#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int n,m;
ll a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	unique(a+1,a+n+1);
	ll ans=a[m];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
