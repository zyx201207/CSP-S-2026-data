#include<bits/stdc++.h>
using namespace std;
long long n,s;
struct node{
	int a,v;
	char c;
}a[210000],x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(a[i].c!=a[n-i+1].c){
			s+=max(a[i].a,a[n-i+1].a);
		}
	}
	cout<<s;
}