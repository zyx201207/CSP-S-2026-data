#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],chg;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);

	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=2;i<=n;++i){
		if(a[i]==a[i-1]){
			cout<<a[i];
			return 0;
		}
	}
	cout<<a[m];
	return 0;
}