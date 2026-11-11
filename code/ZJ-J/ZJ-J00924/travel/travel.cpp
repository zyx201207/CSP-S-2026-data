#include<bits/stdc++.h>
using namespace std;
string s;
struct CYC{
	string num,cnt;
	char ch;
}a[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0].num;
	getchar();
	for(int i=1;i<=3;i++){
		char x=getchar();
		if(isdigit(x))a[0].cnt+=x;
		else a[0].ch=x;
	}
	cin>>a[1].num;
	getchar();
	for(int i=1;i<=3;i++){
		char x=getchar();
		if(isdigit(x))a[1].cnt+=x;
		else a[1].ch=x;
	}
	if(a[0].num==a[1].num){
		s+='1';
		if(a[0].cnt==a[1].cnt){
			s+='1';
			if((a[0].ch<='C'&&a[1].ch<='C')||(a[0].ch>='D'&&a[1].ch>='D')){
				s+='1';
				if(a[0].ch==a[1].ch+1||a[0].ch+1==a[1].ch)s+='1';else s+='0';
			}else s+="00";
		}else s+="000";
	}else s+="0000";
	cout<<s;
	return 0;
}