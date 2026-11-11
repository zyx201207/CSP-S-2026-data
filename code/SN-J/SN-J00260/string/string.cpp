#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		sum+=a;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	long long r=sum%2;		
	long long cnt=0;
	if(r==1){
	    long long t=sum/2;
	    for(long long i=0;i<t;i++){
		    if(s[i]!=s[sum-i-1])cnt++;
	    }
	}
	else{
		long long t=sum/2-1;
		for(long long i=0;i<=t;i++){
		    if(s[i]!=s[sum-i-1])cnt++;
	    }
	} 
	cout<<cnt;
	return 0;
}
