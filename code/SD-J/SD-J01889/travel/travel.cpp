#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int str1=(s1[0]-'0')*10+(s1[1]-'0');
	int str2=(s2[0]-'0')*10+(s2[1]-'0');
	if(str1!=str2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	str1=s1[2]-'A'+1;
	str2=s2[2]-'A'+1;
	if((str1==1&&(str2==2||str2==3))||(str1==2&&(str2==1||str2==3))||(str1==3&&(str2==2||str2==1))||(str1==4 && (str2==6))||(str1==6&&(str2==4)))
		cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if((str1==1&&str2==2)||(str1==2&&(str2==1||str2==3))||(str1==3&&str2==2)||(str1==4&&str2==6)||(str1==6&&str2==4))
		cout<<"1";
	else cout<<"0";
	return 0;
}
