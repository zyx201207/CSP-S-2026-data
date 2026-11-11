#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n;
	cin>>n;
	long long a[n+5];
	char b[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long total=0;
	for(int i=0;i<n;i++){
		total+=a[i];
	}
	long long x=0;
	string s;
    for(int i=0;i<n;i++){
    	for(int j=0;j<a[i];j++){
    		x++;
    	    s[x]=b[i];
    	    cout<<s[x];
  
		}
	}
	long long p=0;
	for(int i=1;i<=x;i++){
		if(s[i]!=s[x-i+1]){
			p++;
		}
	}
    cout<<p/2;

	
	
return 0;
}
