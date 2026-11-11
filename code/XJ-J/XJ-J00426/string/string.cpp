#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],t=1,cnt=0,ans;
char c[200005];
string s;
int gcd(string x){
	for(long long int l=1,r=cnt;l<=cnt,r>=1;l++,r--){
		if(x[l]!=x[r]){
			return 0;
		}	
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long int j=t;j<=t+a[i];j++){
			s[j]=c[i];	
	}
		t+=a[i];
		cnt+=a[i];
	}
	for(long long int i=cnt;i>=1;i--){
    	if(gcd(s)==0){
 			ans++;
			s[i]=s[1];   		
		}
		else{
			cout<<ans;
			break;								
		}
	}
	return 0;	
}