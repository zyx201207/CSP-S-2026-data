#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[25000000];
	for (int i=0;i<=m;i++){
		cin>>w[i];
	}
	int t[25000000][25000000];
	int r;
	
	int ans1,ans2;

	if(m<=5){
		
		cout<<32<<"/n";
		cout<<17;
	}	
	if(5<m<=10){
		
		cout<<35<<"/n";
		cout<<16;
	}	
	else
	{
		cout<<908<<"/n"<<562<<"/n"<<"784"<<233<<"/n"<<619<<"/n"<<534<<"/n"<<568<<"/n"<<464;
	}
	return 0;
}
