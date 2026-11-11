#include <iostream>
#include <cstdio>
using namespace std;
long long ans,len;
string st;
int a,n;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		string s(a,c);
		st=st+s;
		len+=a;
	}
	for(long long i=0;i<len/2;i++){
		if(st[i]!=st[len-1-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
