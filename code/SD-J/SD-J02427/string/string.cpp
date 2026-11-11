#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n,x=0,s=0,r=0;
	cin>>n;
	long long a[n];
	string c;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	r+=a[i];
	}
	string s1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s1[i]=c[i];
		}
	}
	long long m=r-1;
	for(long long i=1;i<=m;i++){
		if(s1[i]!=s1[m]){
			s1[m]=s1[i];
			x++;
		}
		m--;
	}
	long long k=r-1;
	for(long long j=1;j<=k;j++){
		if(s1[j]!=s1[k]){
			s1[j]=s1[k];
			s++;
		}
		m--;
	}
	cout<<min(x,s);
}

