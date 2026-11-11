#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	while(n--){
		long long q;
		cin>>q;
		char a;
		cin>>a;
		while(q--){
			s+=a;
		}
	}
	bool f=1;
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	long long sum1=0,sum2=0;
	string s1,s2;
	if(s.size()%2==0){
		long long mid=s.size()/2;
		long long xb1=0,xb2=0;
		for(long long i=mid-1;i>=0;i--,xb1++){
			s1[xb1]=s[i];
		}
		for(long long j=mid;j<s.size();j++,xb2++){
			s2[xb2]=s[j];
		}
		for(long long i=0;i<xb1;i++){
			if(s1[i]!=s2[i]){
				sum1++;
			}
		}
		cout<<sum1;
	}else{
		long long mid=s.size()/2;
		long long xb1=0,xb2=0;
		for(long long i=mid-1;i>=0;i--,xb1++){
			s1[xb1]=s[i];
		}
		for(long long j=mid+1;j<s.size();j++,xb2++){
			s2[xb2]=s[j];
		}
		for(long long i=0;i<xb1;i++){
			if(s1[i]!=s2[i]){
				sum2++;
			}
		}
		cout<<sum2;
	}
	return 0;
}
