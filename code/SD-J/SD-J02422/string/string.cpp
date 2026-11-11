#include<bits/stdc++.h>
using namespace std;
long long n,l=-1,a,sum;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
			l++;
		}
	}
	for(long long i=0;i<=l-i;i++){
		if(s[i]!=s[l-i]) {
			sum++;
			
		}
	}
	cout<<sum;
	return 0;
} 
