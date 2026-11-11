#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+5],q=0;
	char c[n+5];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
}
	for(int i=0;i<n-i-1;i++){
		if(a[i]!=a[n-i-1]&&c[i]!=c[n-i-1]){
			q+=min(a[i],a[n-i-1]);
		}
		else if(a[i]==a[n-i-1]&&c[i]!=c[n-i-1]){
			q+=a[i];
		}
		
	}
	cout<<q;
	return 0;
}
