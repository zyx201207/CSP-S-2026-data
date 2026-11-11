#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt=0,l;
	char b;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	if(s.length()%2==0){
	    l=s.length()/2;
	}else{
		l=s.length()/2+1;
	}
	for(long long i=0,j=s.length()-1;i<=l,j>=l;i++,j--){
			if(s[i]!=s[j]){
				cnt++;
			}
	}
	cout<<cnt;
	return 0;
}
