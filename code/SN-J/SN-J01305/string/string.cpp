#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll num;
char a[100000000000000005];
struct A{
	int a;
	char b;
};
A in[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>in[i].a>>in[i].b;
		num+=in[i].a;
		for(ll j=1;j<=in[i].a;j++){
			a[i]=in[i].b;
		}
	}
	for(int i=1,j=num;i<=num,j>=1,i!=j;i++,j--){
		if(a[i]!=a[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
