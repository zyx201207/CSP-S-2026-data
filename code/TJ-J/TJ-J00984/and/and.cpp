#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y[200005];
string s;
char c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",strout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>y[i];
	}
	if(m==n){
		x=y[0];
		for(int i=0;i<n;i++){
			x&=y[i];
		}
	}
	else{
		sort(y,y+n);
		if(m==1){
			cout<<y[n-1];
			return 0;
		}
		x=y[n-1];
		for(long long i=n-1;i>n-m-1;i--){
			x&=y[i];
			
		}
	}
	cout<<x;
	return 0;
}
