#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	
	for(long long i=0;i<a;i++){
	    long long n;
	    string c;
	    cin>>n>>c;
	    for(long long i=0;i<n;i++){
	    	s+=c;
		}
}
	long long sum=s.size()-1;
	long long ans=0;
	long long m=sum/2;
	long long j=m+1;
	if((sum+1)%2!=0){
		for(long long i=m-1;i>=0;i--){
			if(s[i]!=s[j++]){
			    ans++;
	        }
	    }
	}else{
		for(long long i=m;i>=0;i--){
			if(s[i]!=s[j++]){
			    ans++;
	        }
		}
	}
	
	cout<<ans;
	return 0;
}
