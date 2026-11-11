#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,a[200010];
char x[200010];
string s;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
		for(int j=1;j<=a[i];j++){
			s=s+x[i];
		}
	}
	l=s.size();
	if(l%2==0){
		for(int i=l/2;i<l;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		}
	}else{
		for(int i=l/2+1;i<l;i++){
	    	if(s[i]!=s[l-i-1]){
	    		ans++;
	    	}
    	}
	}
	cout<<ans;
	return 0;
}
