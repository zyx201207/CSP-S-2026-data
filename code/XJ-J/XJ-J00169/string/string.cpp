#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" ";
	while(n--){
		long long m;
		string ls;
		cin>>m>>ls;
		while(m--)
			s+=ls;
	}
	long long len=s.size();
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i]){
			cnt++;
		}	
	}
	cout<<cnt;
	return 0;
}
