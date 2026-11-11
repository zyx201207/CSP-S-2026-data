#include<bits/stdc++.h>
using namespace std;
long long n,a,num=0,sum=0;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c[i];
		for(long long j=0;j<a;j++){
			s[num]=c[i];
			num++;
		}	
	}
	for(long long x=0;x<num/2;x++){
		if(s[x]!=s[num-x-1])
		  sum++;
	}
	cout<<sum;
	return 0;
}
