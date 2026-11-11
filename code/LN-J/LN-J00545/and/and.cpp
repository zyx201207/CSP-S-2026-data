#include<bits/stdc++.h>
using namespace std;
#define tw long long
const int N=2e5+10;
tw a[N];
string s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	tw n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n];
	return 0;
}
