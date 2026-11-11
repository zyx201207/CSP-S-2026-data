#include<iostream>
using namespace std;
int s[10000];
int a,b,c=0,d=0;;
int main() {
	int n;
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s[c]=b;
			c+=a;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[n-1]=s[0]){
			d+=1;
		}
	}
	cout<<d;
	return 0;
}
