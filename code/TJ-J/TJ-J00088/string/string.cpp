#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,len;
string s;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>ch;
		for(int j=0;j<a;j++){
			s=s+ch;
		}
	}
	len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
