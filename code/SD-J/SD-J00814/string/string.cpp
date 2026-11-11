#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long a[N];
string s[N];
string c;
string c1,c2;
string s3;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i]; 
	}
	if(s[1]==s[n]){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c+=s[i];
		}
	}
	int len=c.length();
	if(len%2==0){
		for(int i=0;i<len/2;i++){
			c1+=c[i];
		}
		for(int i=len/2;i<len;i++){
			c2+=c[i];
		}
	}else{
		for(int i=0;i<len/2;i++){
			c1+=c[i];
		}
		for(int i=len/2+1;i<len;i++){
			c2+=c[i];
		}
	}
	for(int i=c2.length()-1;i>0;i--){
		s3+=c2[i];
	}
	for(int i=0;i<c2.length();i++){
		if(c1[i]!=s3[i])  ans++;
	}
	cout<<ans;
	return 0;
}

