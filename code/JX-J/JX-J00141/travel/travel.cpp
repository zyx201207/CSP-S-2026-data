#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll check[10][10]={
	{0,1,2,0,0},
	{1,0,1,0,0},
	{2,1,0,0,0},
	{0,0,0,0,1},
	{0,0,0,1,0}
};
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		putchar('1');
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			putchar('1');
			if(check[s1[2]-'A'][s2[2]-'A']){
				putchar('1');
				if(check[s1[2]-'A'][s2[2]-'A']==1){
					putchar('1');
				}else{
					putchar('0');
				}
			}else{
				putchar('0');
				putchar('0');
			}
		}else{
			putchar('0');
			putchar('0');
			putchar('0');
		}
	}else{
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
	}
	return 0;
}