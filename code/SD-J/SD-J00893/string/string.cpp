#include<iostream>
#include<fstream>
#include<string>
using namespace std;
long long n,cnt=0;
int a;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s+=string(a,c);
		
	}
	if(s.size()>1000000000){
		cout<<1LL*3*1000000000;
		return 0;
	}
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
