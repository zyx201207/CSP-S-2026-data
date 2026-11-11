#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string c1,c2,s1,s2;

int abs(int a,int b){
	if(a>b) return a-b;
	return b-a;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	char ch1=s1[2],ch2=s2[2];
	
	bool flag1=(c1==c2);
	bool flag2=(flag1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	bool flag3=(flag2&&!((s1[2]<='C')^(s2[2]<='C')));
	bool flag4=(flag3&&(abs(ch1,ch2)==1));
	
	cout<<flag1<<flag2<<flag3<<flag4;
	
	return 0;
}
