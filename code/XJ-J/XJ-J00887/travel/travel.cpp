#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,sum;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a=int(c1[0]-'0')*10+int(c1[1]-'0');
	int b=int(c2[0]-'0')*10+int(c2[1]-'0');
	int c=int(s1[0]-'0')*10+int(s1[1]-'0');
	int d=int(s2[0]-'0')*10+int(s2[1]-'0');
	int e=int(s1[2]-'A')+1,f=int(s2[2]-'A')+1,flag=0;
	if(a==b){
		sum.push_back('1');
		flag=1;
	}else{
		sum.push_back('0');
	}
	if(c==d && flag){
		sum.push_back('1');
	}else{
		sum.push_back('0');
	}
	if(c==d && s1[2]!=s2[2] && ((e<4 && f<4) || (e>3 && f>3)) && flag){
		sum.push_back('1');
	}else{
		sum.push_back('0');
	}
	if((e+1==f || f+1==e) && c==d && !(e==3 && f==4) && !(e==4 && f==3) && flag){
		sum.push_back('1');
	}else{
		sum.push_back('0');
	}
	cout << sum;
	return 0;
}
