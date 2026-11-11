#include<bits/stdc++.h> 
using namespace std;
char a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,o=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		int c;
		char v;
		cin>>c>>v;
		cout<<v;
		for(int j=1;j<=c;j++){
			a[o]=v;
			o++;
		}
		
	}
	cout<<0;
	return 0;
}
