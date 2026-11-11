#include <iostream>
using namespace std;
string a,b,c,d;
int sum[10];
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a>>d>>b;
	if(c[0]==d[0]&&c[1]==d[1])
	{
		sum[0]=1;
	}
	if(sum[0]==0)
	{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		sum[1]=1;
	}
	if(sum[1]==0)
	{
		cout<<"1000";
		return 0;
	}
	cout<<1110;
	return 0;
}
