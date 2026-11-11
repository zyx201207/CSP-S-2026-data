#include<bits/stdc++.h>
using namespace std;
char m[200000000];
long long n; 
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.on","w",stdout);
	cin>>n;
	int s=0,d;
	char a;
	for(int i=0;i<n;i++){
		cin>>sum>>a;
	    d=s;s+=sum;
		for(int j=d;j<s;j++){
			m[j]=a;
		}
	}
	sum=0;
	for(int i=0;i<s-1;i++){
		if(m[i]!=m[s-1]){		
			m[s]=m[i];
			sum+=1;

		}
		s--;
	}
	cout<<sum;
	return 0;
} 
