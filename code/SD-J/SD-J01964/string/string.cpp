#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,x=0;
	char a1;
	string m=" ";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>a1;
		for(long long i=0;i<a;i++)
			m=m+a1;
	}
	if(n==1)cout<<'0';
	else{
		for(long long i=0;i<m.size();i++)
			if(m[i]!=m[m.size()-i])x++;
	}
	cout<<x/2;
	return 0;
} 
