#include<bits/stdc++.h>
using namespace std;
long long n,c,k;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long w;char q;
		cin>>w>>q;
		for(int j=1;j<=w;j++){
			a+=q;
		}
		k+=w;
	}
	for(int i=0;i<k/2;i++){
		if(a[i]==a[k-1-i]){
			continue;
		}c++;
	}cout<<c;
	return 0;
}
