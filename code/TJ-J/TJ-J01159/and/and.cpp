#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],h;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=unique(a,a+n)-a;
	if(m==1) cout<<a[l-1];
	else if(m==n){
		for(int i=0;i<n;i++){
			h&=a[i];
		}
		cout<<h;
	}
	else if(m==2) cout<<a[l-1]&a[l-2];
	else cout<<a[l-m];
	return 0;
}
