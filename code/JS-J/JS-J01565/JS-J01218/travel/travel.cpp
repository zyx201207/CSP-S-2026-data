#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a != c)puts("0000");
	else{
		printf("1");
		if(b[0] != d[0] || b[1] != d[1])puts("000");
		else{
			printf("1");
			if((b[2] <= 'C' && d[2] >= 'D') || (b[2] >= 'D' && d[2] <= 'C'))puts("00");
			else{
				printf("1");
				if(abs(b[2] - d[2]) > 1)puts("0");
				else puts("1");
			}
		}
	}
	return 0;
}
/*
1

02 01A 02 01B

1111

2

02 01C 02 01A

1110

3

02 01C 02 01D

1100

4

02 02B 02 01A

1000

5

02 01A 03 01A

0000
*/
