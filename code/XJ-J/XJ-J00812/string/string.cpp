#include<bits/stdc++.h>
using namespace std;
int n;
char c1;
string s,s1,s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long m;
		char c;
		cin>>m>>c;
		for(int i=1;i<=m;i++){
			s+=c;
		}
	}
	long long l=s.size()-1;
	for(long long i=0;i<=l;i++){
		if(i<s.size()/2){
			s1+=s[i];
		}
		if(i>=s.size()/2){
			s2+=s[i];
		}
	}
	for(int i=s2.size()-1;i>=0;i--){
		s3+=s2[i];
	}
	if(s1==s2){
		cout<<0;
		return 0;
	}
	else{
		long long ans=0,ans1=0;
		for(long long i=0;i<=s1.size()-1;i++){
			if(s1[i]!=s3[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
//abb
//bbc