#include<bits/stdc++.h>
using namespace std;

string s;
long long sum=0;

int check(long long len){
	long long l=len/2-1;
	long long r=len/2+1;
		
	if(len%2==1){
		sum=l+1;
		while(l>=0 or r<len){
			if(s[l]==s[r]){
				l--;
				r++;
				sum-=1;
			}else{
				return 0;
			}	
		}
	}else{
		sum=1;
		r+1;
		while(l>=0 or r<len){
			if(s[l]==s[r]){
				l--;
				r++;
				sum-=1;
			}else{
				return 0;
			}		
		}
	}
	
	return 1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b;
		
		while(a--){
			s+=b;
		}
		
	}
	
	long long len=s.size();

	if(check(len)){
		cout<<0;
		return 0;
	}else{
		cout<<sum;
	}
	
	return 0;
}