#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool u1 = false,u2 = false,u3 = false,ukkksc03 = false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	int l1 = a.size(),l2 = c.size();
	int che1 = 0,che2 = 0;
	for(int i = 0;i < l1;i++){
		if(a[i] == '0')
			continue;
		che1 = che1 * 10 + (a[i] - '0');
	}
	for(int i = 0;i < l2;i++){
		if(c[i] == '0')
			continue;
		che2 = che2 * 10 + (c[i] - '0');
	}
	if(che1 == che2)
		u1 = true;
		int l3 = b.size(),l4 = d.size();
	if(u1){
		int pai1 = 0,pai2 = 0;
		for(int i = 0;i < l3 - 1;i++){
			if(b[i] == '0')
				continue;
			pai1 = pai1 * 10 + (b[i] - '0');
		}
		for(int i = 0;i < l4 - 1;i++){
			if(d[i] == '0')
				continue;
			pai2 = pai2 * 10 + (d[i] - '0');
		}
		if(pai1 == pai2)
			u2 = true;
	}		
	char sum1 = b[l3 - 1],sum2 = d[l4 - 1];
	if(u2){	
		if(sum1 >= 'A'&&sum1 <= 'C'&&sum2 >= 'A'&&sum2 <= 'C')
			u3 = true;
		else if(sum1 >= 'D'&&sum1 <= 'F'&&sum2 >= 'D'&&sum2 <= 'F')
			u3 = true;
	}
	if(u3){
		if((sum1 == 'A'&&sum2 == 'B')||(sum1 == 'B'&&sum2 == 'A'))
			ukkksc03 = true;
		else if((sum1 == 'B'&&sum2 == 'C')||(sum1 == 'C'&&sum2 == 'B'))
			ukkksc03 = true;
		else if((sum1 == 'D'&&sum2 == 'F')||(sum1 == 'F'&&sum2 == 'D'))
			ukkksc03 = true;
	}
	if(u1)
		printf("1");
	else
		printf("0");
	if(u2)
		printf("1");
	else
		printf("0");		
	if(u3)
		printf("1");
	else
		printf("0");
	if(ukkksc03)
		printf("1");
	else
		printf("0");
	return 0;
}
