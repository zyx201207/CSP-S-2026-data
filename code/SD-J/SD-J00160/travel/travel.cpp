#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
bool e[4];
char aa;
char dd;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	aa=b[2];
	dd=d[2];
	int bb=((b[0]-'0')*10)+b[1]-'0';
	int cc=((d[0]-'0')*10)+d[1]-'0';
	if(a==c){
		e[0]=1;
		if(bb==cc){
			e[1]=1;
			if(aa<='C'&&dd<='C'){
				e[2]=1;
				if(aa+1==dd||dd+1==aa){
					e[3]=1;
				}
			}
			else if(aa>'C'&&dd>'C'){
				e[2]=1;
				e[3]=1;
			}
		}
	}
	cout<<e[0]<<e[1]<<e[2]<<e[3];
	return 0;
}
