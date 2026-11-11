#include<bits/stdc++.h>
using namespace std;
int a[1000010];
char b[1000010],c[100001000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=0,f=0;
	long long m=0,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		m+=a[i];	
	}
	m=ceil(m/2);
	
	for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				k++;
				c[k]=b[i];
				
			}
	}
	for(int i=1;i<=m;i++){
		if(c[i]!=c[k-i+1]) f++;
	}
	cout<<f;
	return 0;
} 
