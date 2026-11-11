#include<bits/stdc++.h>
using namespace std;

struct node{
	long long a;
	char c;
}arr[1000001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>arr[i].a>>arr[i].c;
	}
	
	long long k=0;
	while(k<n){
		for(long long i=0;i<arr[k].a;i++){
			s+=arr[k].c;
		}
		k++;
	}
	long long len=s.size();
	long long ans=0;
	if(len%2==0){
		for(long long i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
	}else{
		for(long long i=0;i<len/2-1;i++){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
} 
