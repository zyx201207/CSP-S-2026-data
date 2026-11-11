#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,a,l,ll,t=0;
	char c;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
			s+=c;
	}
	l=s.size(),ll=l/2-1;
	for(long long i=0;i<=ll-1;i++)
		if(s[i]!=s[l-i-1]) t++;
	cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
