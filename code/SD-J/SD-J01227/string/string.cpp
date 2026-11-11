#include<bits/stdc++.h>
using namespace std;
char a[1000000000];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	char b[n];
	long long m,k=0;
	for(int i=0;i<n;i++){
		cin>>m>>b[i];
		for(int j=k;j<k+m;j++)
			a[j]=b[i];
		k+=m;
	}
	for(int i=0;i<k/2;i++)
		if(a[i]!=a[k-i-1]) 
			cnt+=1;
	cout<<cnt;
	return 0;
}
