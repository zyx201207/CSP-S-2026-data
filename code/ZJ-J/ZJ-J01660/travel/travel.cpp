#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define file freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
int main()
{
	file
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)printf("0000");
	else{
		printf("1");
		string p1,p2;
		p1=s1.substr(0,2);
		p2=s2.substr(0,2);
		if(p1!=p2)printf("000");
		else{
			printf("1");
			p1=s1.substr(2);
			p2=s2.substr(2);
			if(p1<="C"&&p1>="A"){
				if(p2<="F"&&p2>="D")
					printf("00");
				else{
					printf("1");
					if(abs(p1[0]-p2[0])==1)
						printf("1");
					else printf("0");
				}
			}
			if(p1<="F"&&p1>="D"){
				if(p2<="C"&&p2>="A")
					printf("00");
				else{
					printf("1");
					if(abs(p1[0]-p2[0])==1)
						printf("1");
					else printf("0");
				}
			}
		}
	}
	return 0;
}//02 01A 02 01B