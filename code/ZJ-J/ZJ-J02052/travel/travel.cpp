#include<bits/stdc++.h>
#define IO freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
using namespace std;
int ans[5];
int main(){
	IO
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		int num1=(s1[0]-'0')*10+(s1[1]-'0');
		int num2=(s2[0]-'0')*10+(s2[1]-'0');
		if(num1==num2){
			ans[2]=1;
			char st1=s1[2],st2=s2[2];
			if((st1<='C'&&st1>='A')==(st2<='C'&&st2>='A')){
				ans[3]=1;
				if(abs(st1-st2)==1)ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}
