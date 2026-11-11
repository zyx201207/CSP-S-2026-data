#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,s;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a=a+y;
		}
	}
	int li=a.size();
	for(int i=0;i<li/2;i++){
		if(a[i]!=a[li-i-1]) s++;
	}
	cout<<s;
	return 0;
}
