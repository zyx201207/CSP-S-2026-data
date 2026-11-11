#include"bits/stdc++.h"
using namespace std;
int c1,c2;
int p1,p2;
char pai1,pai2;
string ans="0000";
int main(){
	//openfree~~~
	//openfree~~~
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>pai1>>c2>>p2>>pai2;
	//cout<<c1<<" "<<p1<<" "<<pai1<<" "<<c2<<" "<<p2<<" "<<pai2;
	if(c1==c2){
		ans[0]='1';
		if(p1==p2){
			ans[1]='1';
			if((pai1<='C')&&(pai2<='C')){
				ans[2]='1';
				int sx=pai1-'A';
				int sr=pai2-'A';
				if((sx-sr==1)||(sr-sx==1)){
					ans[3]='1';
				}
			}else if((pai1>='D')&&(pai2>='D')){
				ans[2]='1';
				int sx=pai1-'A';
				int sr=pai2-'A';
				if((sx-sr==1)||(sr-sx==1)){
					ans[3]='1';
				}
			} 
		}
	}
	cout<<ans;
	return 0;
}
