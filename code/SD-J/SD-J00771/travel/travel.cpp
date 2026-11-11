#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int a=s1[2]-64;
			int b=s2[2]-64;
			if(a==6) a-=1;
			if(b==6) b-=1;
			if((a<=3&&b<=3)||(a>=4&&b>=4)){
				cout<<1;
				if(a-b==1||b-a==1){
					cout<<1;
				} else cout<<0;
			} else cout<<0<<0;
		} else cout<<0<<0<<0;
	} else cout<<0<<0<<0<<0;
	return 0;
}
