#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200010;
ll n;
ll aa;
char b;
string a;
ll cnt=0;
ll lengtha=0;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>aa>>b;
		for(int j=1;j<=aa;j++)
			a+=b;
		lengtha+=aa;
	}
	for(int i=0,j=lengtha-1;i<j,j>i;i++,j--){
		if(a[i]!=a[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}
