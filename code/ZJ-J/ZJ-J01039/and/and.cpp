#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxx;
bool cmp(int x,int y){
	return x>y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	m--;
	for(int i=1;i<n;i++){
		if(m==0) break;
		maxx&=a[i+1];
		m--;
	}
	cout<<maxx<<'\n';
	return 0;
}