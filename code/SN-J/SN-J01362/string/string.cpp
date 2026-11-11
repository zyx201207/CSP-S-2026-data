#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt=0,stp=0,k=0;
	char b;
	string s,ss,sss;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		for(int j=1;j<=a;j++){
			s[++k]=b;
		}
	}
	for(int i=1;i<=k/2;i++){
		ss[i]=s[i];
	}
	for(int i=k/2+1;i<=k;i++){
		cnt++;
		sss[cnt]=s[i];
	}
	for(int i=1;i<=k/2;i++){
		if(ss[i]!=sss[i]){
			stp++;
		}
	}
	cout<<stp;
	return 0;
}
