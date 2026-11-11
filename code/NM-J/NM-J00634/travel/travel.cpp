#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		d[1] = '1';
		if((s1[0] == s2[0])&&(s1[1] == s2[1])){
			d[2] = '1';
			if(((s1[2] == 'D'||s1[2] == 'F')&&(s2[2] == 'D'||s2[2] == 'F'))||(((s1[2] == 'A'||s1[2] == 'B')||s1[2] == 'C')&&((s2[2] == 'A'||s2[2] == 'B')||s2[2] == 'C')))
				d[3] = '1';
			else
				d[3] = '0';
			if(((s1[2] == 'D'||s1[2] == 'F')&&(s2[2] == 'D'||s2[2] == 'F'))||(((s1[2] == 'A'||s1[2] == 'B')&&(s2[2] == 'A'||s2[2] == 'B'))||((s1[2] == 'B'||s1[2] == 'C')&&(s2[2] == 'B'||s2[2] == 'C'))))
				d[4] = '1';
			else
				d[4] = '0';
			}
		else{
			d[2] = '0';
			d[3] = '0';
			d[4] = '0';
		}
	}
	else{
		d[1] = '0';
		d[2] = '0';
		d[3] = '0';
		d[4] = '0';
	}
	for(int i = 1;i <= 4;i++)
		cout<<d[i];

	return 0;
}
