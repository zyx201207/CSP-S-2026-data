#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,tot=0;
	cin>>n;
	string s;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		tot+=a;
		while(a--){
			s+=c;
		}
	}
	long long len=tot/2,i=0,j=tot-1,cnt=0;
	while(len--){
		if(s[i]!=s[j]) cnt++;
		i++;
		j--;
	} 
	cout<<cnt;
	return 0;
}
