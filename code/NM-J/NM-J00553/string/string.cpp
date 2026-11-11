#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,aa=0,mmax=0,mmin=1000000000,cnt=0,cc;
	cin>>n;
	int a[n+5];
	char c[n+5],b[n+5];
	string s;
	cin>>a[1]>>c[1];
	cnt+=a[1];
	if(a[1]>mmax) mmax=a[1];
	if(a[1]<mmin) mmin=a[1];
	cc++;
	b[c[1]-'a'+1]=1;
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]) aa++;
		if(a[i]>mmax) mmax=a[i];
	    if(a[i]<mmin) mmin=a[i];
		cnt+=a[i];
		if(b[c[i]-'a'+1]==0){
			cc++;
			b[c[i]-'a'+1]=1;
		}
	}
	if(aa+1==n) cout<<'0';
	else cout<<cnt/mmax/cc*mmin;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
