#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
string ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){   
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);  
	cin>>n>>m;
	for(int i=1;i<=n;i++)    cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[m]<<'\n';
	return 0;
}
