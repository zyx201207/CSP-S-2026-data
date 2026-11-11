#include<bits/stdc++.h>
using namespace std;
long long n,m,q=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			q++;
		}
	}
	if(q==n){
		cout<<'0';
	}
	sort(a+1,a+n+1);
	cout<<a[n/2];
}
