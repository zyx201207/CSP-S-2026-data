#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	bool f1=(s1==s3),f2=(s2[0]==s4[0])&&(s2[1]==s4[1]),f3=(((s2[2]<='C')&&(s4[2]<='C'))||((s2[2]>'C')&&(s2[4]>'C'))),f4=(abs(s2[2]-s4[2])==1);
	cout<<f1;
	cout<<(f1&&f2);
	cout<<(f1&&(f2&&f3));
	cout<<((f1&&f2)&&(f3&&f4));
	fclose(stdin);
	fclose(stdout);
    return 0;
}
