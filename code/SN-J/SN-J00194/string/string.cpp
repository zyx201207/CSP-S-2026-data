#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;cin>>n;
	long long a;
	string c;
	string s;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	long long p1=0,p2=s.length()-1;
	long long sum=0;
	while(p1<=p2){
		if(s[p1]!=s[p2]) sum++;
		p1++;
		p2--;
	}
	cout<<sum;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
