#include<bits/stdc++.h>
using namespace std;
char c[200005],s[200005],s1[200005],cc[1005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int z=0,k=1;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a>>c[i];
		z+=a;
		for(int g=k;g<=z;g++){
			s[g]=c[i];
			s1[g]=c[i];
			cc[c[i]]++;
		}
		k+=a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=z;i++){
		if(s[i]!=s1[z-i+1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	int m=99999;
	for(int i=int('a');i<=int('z');i++){
		if(cc[i]<m){
			m=cc[i];
		}
	}
	cout<<m;
	return 0;
} 
