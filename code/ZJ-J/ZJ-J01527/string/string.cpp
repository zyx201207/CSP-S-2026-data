#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
char c;
string s="",s2="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
			s2=c+s2;
		}
		sum+=a;
	}
	if(s==s2){cout<<0;return 0;}
	cout<<(ceil(n/2)*sum);
	return 0;
}