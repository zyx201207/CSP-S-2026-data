#include <bits/stdc++.h>
using namespace std;
long long a[1000005],l,n,ans;
string s,b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	
	l=s.size();
	long long c=l/2;
	
	for(long long i=0;i<c;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		} 
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

