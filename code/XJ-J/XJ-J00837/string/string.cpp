#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
long long cd;
bool hw(){
	if (n%2==1){
		for (int i=1,j=n;i<=(n-1)/2,j>=(n+1)/2+1;i++,j--){
			if (c[i]!=c[j]) return 0;
		}
	}else{
		for (int i=1,j=n;i<=n/2,j>=n/2+1;i++,j--){
			if (c[i]!=c[j]) return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cd+=a[i];
	}
	if (hw()) cout<<0;
	else{
		if (cd%2==1){
			cout<<(cd-1)/2;
		}else{
			cout<<cd/2;
		}
	}
	return 0;
}