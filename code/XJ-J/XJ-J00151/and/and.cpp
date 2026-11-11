#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.ans","w",stdout);
	freopen("and2.in","r",stdin);
	freopen("and2.ans","w",stdout);
	freopen("and3.in","r",stdin);
	freopen("and3.ans","w",stdout);
	freopen("and4.in","r",stdin);
	freopen("and4.ans","w",stdout);
	freopen("and5.in","r",stdin);
	freopen("and5.ans","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0; 
} 
