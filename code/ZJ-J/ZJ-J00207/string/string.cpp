#include<bits/stdc++.h>
using namespace std;
long long n,x,p,sum;
char c;
map<char,char> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++) s[p+j]=c;
		p+=x;
	}
	for(int i=1;i<=p/2;i++){
		if(s[i]!=s[p-i+1]) sum++;
	}
	cout<<sum;
    return 0;
}