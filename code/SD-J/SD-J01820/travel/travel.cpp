#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,i,k,a = 0,b = 0,c = 0,d = 0,h1,h2,mi,ma;
	string c1,s1,c2,s2,p1,p2;
	cin>>c1>>s1>>c2>>s2;
	for(i =0;i < 2;i ++){
		p1 = p1 + s1[i];
		p2 = p2 + s2[i];
	}
	h1 = s1[2] - 'A' + 1;h2 = s2[2] - 'A' + 1;
	if(h1 == 4) h1 ++;
	if(h2 == 4) h2 ++;
	if(c1 == c2){
		a = 1;
		if(p1 == p2){
			b = 1;
			k = (h1 + h2) / 2;
			if(k != 3 && k != 4){
				c = 1;
				mi = min(h1,h2);
				if(k == mi){
					d = 1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
}
