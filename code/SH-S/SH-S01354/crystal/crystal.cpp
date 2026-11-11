#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool ts1=1,ts2=1;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			ts1=0;
		}
	}
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			ts2=0;
		}
	}
	if(ts1){
		int b=0;
		for(int i=1;m-i>=0;i++){
			m-=i;
			b++;
		}
		cout<<b;
	}
	else if(ts2){
		int gc=a[2]-a[1],b=1;
		for(int i=gc;m-i>=0;i+=gc){
			m-=i;
			b++;
		}
		cout<<b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
