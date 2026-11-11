#include<bits/stdc++.h>
using namespace std;
bool xiao(int x){
	int sum=0;
	sum=x%2;
	x=x/2;
}
string x,y;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m,a;
	int maxx=-1100;
	cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a;
			x[i]=xiao(a);
		}
	for(int i=1;i<=n;i++){
			y[i]=x[m]&&x[m+1]&&x[m+2];
		}
		for(int i=1;i<=n;i++){
			if(y[i]>maxx){
				maxx=y[i];
			}
		}
		
		cout<<maxx;
	return 0;
} 
