#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	int a2=(c[0]+c[1])-'0',b2=(d[0]+d[1])-'0';
	char a3=c[2],b3=d[2];
	if(a==b){
		cout<<1;
		if(a2==b2){
			cout<<1;
			if((abs(a3-b3)==1&&a3+b3!='C'+'D') || (a3<'D' && b3<'D')){
				cout<<1;
				if(abs(a3-b3)==1&&a3+b3!='C'+'D') cout<<1;
				else cout<<0;
			}	
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
