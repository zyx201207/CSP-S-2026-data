#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+20;
string q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[N];
	char s[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	bool x=true; 
	for(long long i=0;i<n-1;i++){
		if(s[i]!=s[i+1]){
			x=false;
			break;
		}
	}
	if(x==true){
		cout<<0;
		return 0;
	}
	long long ans=0;      
	for(long long i=0;i<n;i++){
		 for(long long j=0;j<a[i];j++){
		 	q=q+s[i];
		 }
	}
	for(long long l=0,r=q.size()-1;l<=q.size()/2,r>=(q.size()+1)/2;l++,r--){
		if(q[l]!=q[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
