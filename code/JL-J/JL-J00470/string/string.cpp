#include<iostream>
#include<string>
using namespace std;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	string a;
	int n,b;
	long long m=0;
	char t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>t;
		m+=b;
		for(int j=1;j<=b;j++){
			a+=t;
		}
	}
	long long c=0,d=0;
	while(c<m-c-1){
		if(a[c]!=a[m-c-1]){
			d++;
		}
		c++;
	}
	cout<<d;
	return 0;
}
