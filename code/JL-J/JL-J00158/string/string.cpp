#include<bits/stdc++.h>
using namespace std;
const int N=2e9+10;
long long a,p=0,cnt=0;
char c,s[N];
void full(int x,char y){
	for(int i=p;i<p+x;i++){
		s[i]=y;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		full(a,c);
		p+=a;
	}
	for(int i=0;i<(p/2);i++){
		if(s[i]!=s[p-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
