#include<bits/stdc++.h>
using namespace std;

long long n,ans;
string m;
struct date{
	long long s;
	string a;
}str[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>str[i].s>>str[i].a;
		for(long long j=0;j<str[i].s;j++){
			m=m+str[i].a;	
		}
	}
	
	for(long long i=0;i<(m.size()+1)/2;i++){
		if(m[i]!=m[m.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
