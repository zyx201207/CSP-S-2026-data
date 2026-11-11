#include<bits/stdc++.h>
using namespace std;
char a[1000010],y;
int j;
long long b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>j;
	for(int i=0;i<j;i++){
		cin>>b>>y;
		c+=b;
		for(int x=0;x<b;x++){
			a[i]=y;
		}
	}
	cout<<c/2;
	return 0;
}
