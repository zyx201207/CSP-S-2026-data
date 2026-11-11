#include<bits/stdc++.h>
using namespace std;
int a,aa;
char b[4],bb[4];
bool c[128];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>a>>b>>aa>>bb;
	c['A']=1;
	c['B']=1;
	c['C']=1;
	b[0]=(b[0]-'0')*10+(b[1]-'0');
	bb[0]=(bb[0]-'0')*10+(bb[1]-'0');
	if(a==aa){
		cout<<1;
		if(b[0]==bb[0]){
			cout<<'1';
			if(c[b[2]]==c[bb[2]]){
				cout<<1;
				if((b[2]+1==bb[2])||(b[2]-1==bb[2])){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}