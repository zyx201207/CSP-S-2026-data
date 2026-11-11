#include<bits/stdc++.h>
using namespace std;
struct str{
	int si;
	char c;
}a[2010101];
int n;
int main(){
freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		int a;
		string d;
		cin>>a>>d;
		cout<<0;
	}else 
	if(n==2){
		cin>>a[1].si>>a[1].c;
		cin>>a[2].si>>a[2].c;
		if(a[1].c==a[2].c)
			cout<<0;
		else
			cout<<min(a[1].si,a[2].si);
	}
	return 0;
} 
