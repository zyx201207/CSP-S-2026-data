#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,c=1,d[200001],h=1,g,f,e=1,maxn=0;
	cin>>a>>b;
	while(c<=a){
		cin>>d[c];
		c++;
	}
	d[0]=d[a];
	while(e<=a){
		g=e+1,h=1;
		f=d[e];
		while(h<=b){
			f=f&d[g%a]; 
			h++,g++;
		}
		if(f>maxn)
		maxn=f;
		e++;
	}
	sort(d+1,d+a+1);
	e=1;
	while(e<=a){
		g=e+1,h=1;
		f=d[e];
		while(h<=b){
			f=f&d[g%a]; 
			h++,g++;
		}
		if(f>maxn)
		maxn=f;
		e++;
	}
	cout<<maxn<<endl;
	return 0;
}
