#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
string c,s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(long long j=0;j<a[i];j++){
			s+=c;
		}
	}
	string s1,s2,s3;
	if(s.size()%2==0){
		for(long long i=0;i<s.size()/2;i++){
			s1+=s[i];
		}
		for(long long i=s.size()/2;i<s.size();i++){
			s2+=s[i];
		}
		for(long long i=s2.size()-1;i>=0;i--){
			s3+=s2[i];
		}
		for(long long i=0;i<s1.size();i++){
			if(s1[i]!=s3[i]){
				sum++;
			}
		}

	}else{
		for(long long i=0;i<s.size()/2;i++){
			s1+=s[i];
		}
		for(long long i=s.size()/2+1;i<s.size();i++){
			s2+=s[i];
		}
		for(long long i=s2.size()-1;i>=0;i--){
			s3+=s2[i];
		}
		for(long long i=0;i<s1.size();i++){
			if(s1[i]!=s3[i]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}