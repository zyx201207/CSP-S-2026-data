#include<bits/stdc++.h>
using namespace std;
long long sum=1,ok,n,b;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>s;
		for(int j=sum;j<=sum+b-1;j++){
			s1[j]=s[0];
		}
		sum+=b;
	}
	
	for(int i=1;i<=(sum-1)/2;i++){
		if(s1[i]!=s1[sum-i]){
			ok++;
		}
	}
	cout<<ok;
	return 0;
}
