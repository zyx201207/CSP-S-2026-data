#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
struct sstring{
	int n;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].n>>a[i].s;
	}
	for(int i=1;i<=n/2;i++){
		if(a[i].n!=a[1+n-i].n){
			a[i].n-=(a[1+n-i].n-a[i].n);
			a[i+1].n+=(a[1+n-i].n-a[i].n);
			i--;
			continue;
		}
		else{
			if(a[i].s!=a[1+n-i].s){
				num+=a[i].n;
			}
		}
	}
	cout<<num;
	freopen("CON","w",stdout);
	cout<<num;
	return 0;
}

