#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	long long n[5000005];
	for(int i = 0;i<a;i++){
		cin>>n[i];
	}
	cout<<a<<b<<n[0];
	return 0;
}
