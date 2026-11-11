#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char d1,d2;
	scanf("%d %d%c %d %d%c",&c1,&s1,&d1
	,&c2,&s2,&d2);
	if(c1==c2){
		cout << 1;
		if(s1==s2){
			cout << 1;
			if((d1<='C'&&d2<='C') || (d1>='d'&&d2>='f'))
			{
				cout << 1;
				if(d1+1==d2 || d1-1==d2)
				{
					cout << 1;
				}else if(d1=='D' && d2=='F'){
					cout << 1;
				}else if(d1=='F' && d2=='D'){
					cout << 1;
				}
				else {cout << 0;}
			}
			else {cout << "00";}
		}
		else {cout << "000";}
	}
	else {cout << "0000";}
	return 0;
 } 
