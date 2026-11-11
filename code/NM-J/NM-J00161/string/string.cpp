#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a;
	int b,c=1,d,e=1,f[500000],g=1,h=0,i;
	cin>>b;
	while(c<=b){
		cin>>d>>a; 
		while(d--){
			f[e]=int(a);
			e++;
		}
		c++;
	}
	e--,i=e;
	while(g<=i/2){
		if(f[g]!=f[e])
		h++;
		g++,e--;
	}
	cout<<h<<endl;
	return 0;

}
