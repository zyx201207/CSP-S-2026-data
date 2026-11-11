#include <bits/stdc++.h>
using namespace std;
struct asd{
	int d;
	char c;
}x[100050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,p=0,l;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i].d);
		cin>>x[i].c;
		for(int j=0;j<x[i].d;j++){
			s+=x[i].c;
		}
	}
	l=s.size();
	for(int i=0;i<(l/2);i++){
		if(s[i]!=s[l-i-1]){
			p++;
		}
	}
	printf("%lld",p);
	
	return 0;
}
