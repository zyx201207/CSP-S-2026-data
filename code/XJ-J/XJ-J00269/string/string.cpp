#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char c;
}a[100005];
int n,f=0;
long long l=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		if(i>=2&&a[i].c!=a[i-1].c)f=1;
		l+=a[i].num;
	}
	if(f)cout<<l/2;
	else cout<<0;
	return 0;
}
