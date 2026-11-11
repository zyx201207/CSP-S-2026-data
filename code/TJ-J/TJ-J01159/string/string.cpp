#include <bits/stdc++.h>
using namespace std;
struct damn{
	long long k;
	char c;
};
damn a[200005];
long long n,g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].k>>a[i].c;
	}
	long long l=0;
	for(int i=0,j=n-1;i<j;){
		l=min(a[i].k,a[j].k);
		if(a[i].c!=a[j].c){
			g+=l;
		}
		a[i].k-=l,a[j].k-=l;
		if(a[i].k<=0) i++;
		if(a[j].k<=0) j--;
	}
	cout<<g;
	return 0;
}
