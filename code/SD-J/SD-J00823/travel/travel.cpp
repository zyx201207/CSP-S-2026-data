#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1,s2,s3,z1,z2,z3;
	cin>>c1>>s1>>s2>>s3 >> c2>>z1>>z2>>z3;
	if(c1!=c2) cout <<"0000";
	else if(c1==c2&&s2==z2&&(s3=='f'||s3=='D'&&z3=='C')) cout << "1100";
	else if(c1==c2&&s2==z2&&(z3=='f'||z3=='D'&&s3=='C'))	cout << "1100";
	else if(c1==c2&&s2==z2&&(s3==z3+1&&s3!='C'||s3==z3-1&&s3!='D')) cout << "1111";
	else if(c1==s1&&s2==z2&&(s3!=z3+1||s3!=z3-1)) cout << "1110";
	else if(c1==c2&&s2==z2&&s3!=z3+1&&s3!=z3-1) cout << "1110";
	else if(c1==c2&&s2!=z2) cout << "1000";
	return 0;
}

