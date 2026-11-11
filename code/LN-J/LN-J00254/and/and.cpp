#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	m-=1;
	int b=2;
	while(m--){
		ans=ans&a[b++];
	}
	cout<<ans;
	return 0;
}

