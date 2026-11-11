#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e6;
int c,n;
int w[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>w[i];
		}
		cout<<abs(w[n]-b);
		cout<<endl;
	}
	return 0;
}
