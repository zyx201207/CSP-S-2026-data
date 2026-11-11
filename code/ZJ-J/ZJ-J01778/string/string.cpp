#include<bits/stdc++.h>
using namespace std;
long long n,n1,a,l,r,s;
string c;
char b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=n1+1;j<=n1+a;j++) c[j]=b;
		n1+=a;
	}
	l=1;
	r=n1;
	while(l<r){
		if(c[l]!=c[r]) s++;
		l++;
		r--;
	}
	cout<<s;
	return 0;
}