#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
long long n,m,a[N],ans;
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
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i];
//	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}

