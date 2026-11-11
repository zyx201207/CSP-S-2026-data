#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		printf("0000");
		return 0;
	}
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		printf("1000");
		return 0;
	}
	int lie1=c1[2]-'A',lie2=c2[2]-'A';
	int side1,side2;
	if(lie1>=0&&lie1<=2) side1=1;
	else side1=2;
	if(lie2>=0&&lie2<=2) side2=1;
	else side2=2;
	if(side1!=side2){
		printf("1100");
		return 0;
	}
	if(abs(lie1-lie2)>1){
		printf("1110");
		return 0;
	}
	printf("1111");
	return 0;
}
