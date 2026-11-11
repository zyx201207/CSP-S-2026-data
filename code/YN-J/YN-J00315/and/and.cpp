#include<bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
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
	sort(a+1,a+1+n,cmp);

	cout<<a[m];
	return 0;
}
