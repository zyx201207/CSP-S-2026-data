#include<bits/stdc++.h>
using namespace std;
long long n;
char a[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x>>a[i];
		s+=x;
	}
	int o=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			o++;
		}
	}
	if(o==1){
		cout<<0;	
	}
	cout<<s/2;
	return 0;
} 
