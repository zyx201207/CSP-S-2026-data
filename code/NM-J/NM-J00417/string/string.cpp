#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,x,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>b;
		for(int j=1;j<=m;j++){
			a+=b;
		}
		b="";
	}
	x=a.size();
	for(long long i=0;i<=x/2;i++){
		if(a[i] != a[x-i-1]){
			a[x-i-1]=a[i];
			s++;
		}
	}
	cout<<s;
	return 0;
}
