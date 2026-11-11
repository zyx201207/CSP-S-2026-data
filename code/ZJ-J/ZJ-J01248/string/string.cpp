#include<bits/stdc++.h>
using namespace std;
int n,sum=0,ans=0;
string s;
int d(int x){
	return sum-1-x;
}
int main(){
	freopen("string.in","r+",stdin);
	freopen("string.out","w+",stdout);
	cin>>n;
	long long now_=1;
	for (int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		s+=a*b;
		sum+=a;
	}
	for (int i=0;i<sum;i++){
		if (s[i]!=s[d(i)]) ans++;
	}
	cout<<ceil(1.0*ans/2);
}
