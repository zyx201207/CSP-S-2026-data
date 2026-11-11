#include<bits/stdc++.h>
using namespace std;
int m,a,n,s[20005],s1[20005],p=0,b;
long long q=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>b;
		s[i]=b;
	};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a=s[i]^s[j];
			s1[p]=a;
			p++;
		};
	};
	for(int j=0;j<p;j++){
		if(s1[j]>q)q=s1[j];
	};
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
