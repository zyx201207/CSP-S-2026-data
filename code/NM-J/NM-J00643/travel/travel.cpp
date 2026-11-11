#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cn,cm,sn,sm;
	cin >> cn >> sn >> cm >> sm;
	bool a=0,b=0,n=0,m=0;
	if(cn==cm){
		a=1;
	}else{
		a=0;
	}
	if(sn=="01A"||"02A"||"03A"||"04A"||"05A"||"06A"||"07A"||"08A"||"09A"){
		if(sn=="01B"||"02B"||"03B"||"04B"||"05B"||"06B"||"07B"||"08B"||"09B"){
			if(sn=="01C"||"02C"||"03C"||"04C"||"05C"||"06C"||"07C"||"08C"||"09C"){
				if(sn=="01D"||"02D"||"03D"||"04D"||"05D"||"06D"||"07D"||"08D"||"09D"){
					if(sn=="01F"||"02F"||"03F"||"04F"||"05F"||"06F"||"07F"||"08F"||"09F"){
							if(sn-1==sm){
								b=1;
							}else{
								b=0;
							}
					}
				}
			}
		}
	}
	if((sn>="A"&&sn<="C")&&(sm>="A"&&sm<="C")||(sn>="D"&&sn<="F")&&(sm>="D"&&sm<="F")){
		n=1;
	}else{
		n=0;
	}
	cout << a << b << n << m;
    return 0;
}
