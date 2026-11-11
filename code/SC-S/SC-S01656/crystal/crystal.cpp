#include<iostream>
#include<algorithm>
using namespace std;
int a[500001];
long long b[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
	b[1]=0;
	int i;
	for(i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
		if(b[i]<b[i-1]) break;
		if(b[i]>m) break;
	}
	cout<<i-1;
	
} 