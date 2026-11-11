#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	string s1,s2,c1,c2;
	cin >> c1 >>s1>>c2>>s2;
	if (c1==c2) cout <<"1";
	else cout << "0";
	string s3,s4;
	s3=s1[0]+s1[1];
	s4=s2[0]+s2[1];
	if ((s3==s4)&&(c1==c2)) cout <<"1";
	else cout << "0";
	string str1,str2;
	str1=s1[2];
	str2=s2[2];
	if (((str1=="D"&&str2=="F")||(str1=="F"&&str2=="D")) &&(s3==s4)) cout <<"1";
	else if (((str1=="B"&&str2=="C")||(str1=="C"&&str2=="B"))&&(s3==s4)) cout <<"1";
	else if (((str1=="A"&&str2=="B")||(str1=="B"&&str2=="A"))&&(s3==s4)) cout <<"1";
	else if (((str1=="A"&&str2=="C")||(str1=="C"&&str2=="A"))&&(s3==s4)) cout <<"1";
	else cout <<"0";
	if (((str1=="A"&&str2=="B")||(str1=="B"&&str2=="A"))&&(s3==s4)) cout <<"1";
	else if (((str1=="B"&&str2=="C")||(str1=="C"&&str2=="B"))&&(s3==s4)) cout <<"1";
	else if (((str1=="D"&&str2=="F")||(str1=="F"&&str2=="D"))&&(s3==s4)) cout <<"1";
	else cout <<"0";
	return 0;
}

