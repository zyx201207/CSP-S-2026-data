#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0;
char c;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s1+=c;
		}
	}
	s2=s1;
	reverse(s2.begin(),s2.end());
	if(s2==s1){
		cout<<0;
	}
	else{
		for(long long i=0;i<s1.size()/2;i++){
			if(s1[i]!=s2[i]){
				sum++;
			}
			
		}
		cout<<sum;
	}
	
	return 0;
} 
