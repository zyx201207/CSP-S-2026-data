#include<bits/stdc++.h>
using namespace std;
string s,c;
int m[1000005],q[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		q[i]=m[i]+q[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=m[i-1];j<q[i];j++){
			s[j]=c[i];
		}
	}

	long long l=0;
	for(int i=1;i<=n;i++){
		l+=m[i];
	}
	long long ans=0;
	if(l%2==0){
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i]) ans++;
		}
	}
	else{
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-1-i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
