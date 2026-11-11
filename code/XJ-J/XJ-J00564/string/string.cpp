#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	
	string S,c1,c2,c3;
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>c1>>c2>>c3;
		S = S+c1+c2+c3;
	}
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}