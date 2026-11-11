#include<bits/stdc++.h>
using namespace std;
string m;
int a,cnt;
long long c;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==sum) bol=1;
		else bol=0;
		sum=c[i];
	}
	if(bol==1) cout<<0;
	for(int i=1;i<=n;i++){
		for(int i=1;j<=a;j++){
			m=m+c[j];
		}
	}
	cout<<cnt;
	return 0;
}