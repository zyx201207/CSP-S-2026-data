#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=1,s=0;
	string z;
	cin>>n;
	for(int i=1;i<=n;i+=1){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			z[t]=c;
			t++;
		}
	}
	long long p=t/2;
	for(int i=1;i<=p;i++){
		if(z[i]!=z[t-i]) s++;
	}
	cout<<s;
	return 0;
}