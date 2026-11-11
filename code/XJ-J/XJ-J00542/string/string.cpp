#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		int a;
		char c;
		cin>>a>>c;
		for(int j=1; j<=a; j++) {
			s+=c;
		}
	}
	int l=s.size();
	int len1,len2;
	if(l%2==1){
		len1=l/2;
		len2=len1+1;
	}
	else{
		len1=l/2;
		len2=len1;
	}

	string s1;
	for(int i=s.size()-1; i>=len2; i--) {
		s1+=s[i];
	}
	//cout<<s<<"\n";
	//cout<<s1<<"\n";
	//cout<<len1<<" "<<len2<<"\n";
	for(int i=0;i<len1;i++){
		//cout<<s1[i]<<" "<<s[i]<<"\n";
		if(s1[i]!=s[i])cnt++;
	}	
	cout<<cnt;
	return 0;
}


