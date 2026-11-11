#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f;
	int sum=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		sum=1000;
        cout<<sum;
	}
	if(b==d){
		cout<<"0000";
	}
	return 0;
}
