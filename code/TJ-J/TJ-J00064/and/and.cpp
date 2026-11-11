#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	long long m=0;
	cin>>a>>b;
	long long n[210086];
	for(int i=1;i<=a;i++){
	cin>>n[i];
	}
	if(b==1){
	for(int i=1;i<=a;i++){
	m=max(n[i],m);
	}
	cout<<m;
	return 0;
	}
	cout<<n[a];
	return 0;
}
