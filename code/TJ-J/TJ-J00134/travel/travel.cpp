#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,n,m;
	cin>>a>>b>>n>>m;
	for(int i=1;i<=b.length();i++){
		if((b=="A"&&m=="C")||(b=="B"&&m=="C")||(b=="F"&&m=="D")||(m=="A"&&b=="C")||(m=="B"&&b=="C")||(m=="F"&&b=="D")){
			cout<<"1111";
			
			
		}
		else{
			cout<<"1110";
		}
	}
	return 0;
	
	
}
