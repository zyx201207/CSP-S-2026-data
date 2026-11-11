#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=2e5+5;
long long a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	CLOSE
	int n,m;
	long long ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
