#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c=1,d,e,sum=0;
char b[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=c;j<=c+a[i]-1;j++){
			s[j-1]=b[i];
		}
		c+=a[i];
	}
	d=0;
	e=c-2;
	for(long long i=1;i<=(c-1)/2;i++){
		if(s[d]!=s[e]){
			sum++; 
		}
		else{
		}
		d++;
		e--;
	}
	cout<<sum;
	return 0;
} 
