#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;

const int N=1e6+5;
ll tp[N];
ll a=0,b=0;
bool pd(string x,string y){
	ll k1=x[2],k2=y[2];
	if (abs(k1-k2)==1){
		return true;
	}
	else {
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	
	ll c1,c2;
	string s1,s2;

	cin>>c1>>s1>>c2>>s2;
	for (int i=0;i<=1;i++){
		a=a*10+(s1[i]-'0');
		b=b*10+(s2[i]-'0');
	}
	ll flg1=0,flg2=0,flg3=0,flg4=0;
	if (c1==c2){
		flg1=1;
		if (a==b){
			flg2=1;
			if ((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')){
				if (s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
					flg3=1;
					if (pd(s1,s2)) flg4=1;
				}
				
			}
			else {
				if (s2[2]=='E'||s2[2]=='D')flg3=1;
			}
		}
	}
	cout << flg1<<flg2<<flg3<<flg4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
