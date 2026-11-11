#include<bits/stdc++.h>
using namespace std;
long long n,m,s[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	int j=0;
	cout<<s[n-m];
	return 0;
}
