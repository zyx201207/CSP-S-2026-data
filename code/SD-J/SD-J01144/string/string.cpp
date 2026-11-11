#include<bits/stdc++.h>
using namespace std;
int n,f;
long long b[200],sum;
struct node{
	long long s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		if(i>=2&&a[i-1].c!=a[i].c){
			f=0;
		}
	}
	if(n==1&&f==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum+=a[i].s;
		b[a[i].c]+=a[i].s;
	}
	long long maxx=-1e9;
	for(int i='a';i<='z';i++){
		if(b[i]>maxx){
			maxx=b[i];
		}
	}
	cout<<sum-maxx;
	return 0; 
} 
