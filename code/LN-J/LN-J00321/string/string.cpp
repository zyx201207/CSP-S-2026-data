#include<bits/stdc++.h>
using namespace std;
string a;
int n,m,c,d;
char g;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>g;
		while(m--){
			a+=g;
			c++;
		}
	}
	for(int i=0;i<c/2;i++){
		if(a[i]!=a[c-i-1]){
			d++;
		}
	}
	cout<<d;
	return 0;
}
