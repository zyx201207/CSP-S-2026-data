#include<cstdio> 
#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<0<<1<<1<<0;
	}else{
		cout<<1<<1<<1<<1;
	}
	return 0;
}
