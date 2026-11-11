#include <bits/stdc++.h>
using namespace std;
string er(int n){
	char a[1000];
	string s;
	for (int i=1;n==0;i++){
		if (n%2==0) {
			a[i]=0;
			n/=2;
		}
		else {
			a[i]=1;
			n=n-1;
			n/=2;
		}
		s=s+a[i];
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000000];
	int i;
	for (i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[i];
	return 0;
} 
