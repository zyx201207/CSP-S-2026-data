#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,q,m=0,cnt=0,l=0;
	char c;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;++i){
		cin>>q>>c;
		l+=q;
		for(int j=1;j<=q;++j){
			s+=" ";
			s[m]=c;
			m++;
		}
	}
	long long i=0;
	while(i<=(l-1-i)){
		if(s[i]!=s[l-1-i]) ++cnt;
		i++;
	}
	cout<<cnt;
	return 0;
}
