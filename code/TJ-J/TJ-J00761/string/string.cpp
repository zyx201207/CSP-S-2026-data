#include<bits/stdc++.h>
using namespace std;
const int MX = 100005;
string a[MX];
long long m[MX],p,con,l;
string c[MX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
		for(int i = 0;i<n;i++){
		cin>>m[i]>>a[i];
		l+=m[i];
		for(int j = 0;j<m[i];j++){
			c[p] = a[i];
			p++;
		}
	}
	for(int i = 0;i<l/2;i++){
		if(c[i]!=c[l-1-i]){
			con++;
		}
	}
	cout<<con;
	return 0;
}
