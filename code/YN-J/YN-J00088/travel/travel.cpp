#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char word1,word2;
long long num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	num1=(s1[0]-'0')*10+s1[1]-'0';
	num2=(s2[0]-'0')*10+s2[1]-'0';
	word1=s1[2];
	word2=s2[2];
	if(c1!=c2)cout<<"0000";
	else{
		cout<<1;
		if(num1!=num2)cout<<"000";
		else{
			cout<<1;
			if(('A'<=word1&&word1<='C'&&'A'<=word2&&word2<='C')||('D'<=word1&&word1<='F'&&'D'<=word2&&word2<='F')){
				cout<<1;
				if((word1-word2==1)||(word2-word1==1))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
	}
}
