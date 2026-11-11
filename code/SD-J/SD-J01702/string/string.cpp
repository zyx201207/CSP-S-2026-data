#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,num=0;
	cin>>n;
	string s;
	char c;
	for(int i=1;i<=n;i++){
		long long a,b=0;
		cin>>a>>c;
		while(b<a){
			s+=c;
			b+=1;
		}
	}
	m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			num+=1;
		}
	}
	cout<<num;
	return 0;
}
