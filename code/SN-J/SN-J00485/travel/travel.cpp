#include<bits/stdc++.h>
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
		char x=a1[0],y=a1[1];
		string p1="";
		p1+=x;
		p1+=y;
		x=b1[0],y=b1[1];
		string p2="";
		p2+=x;
		p2+=y;
		if(p1==p2){
			cout<<1;
			x=a1[2];
			y=b1[2];
			if(((x>='A'&&x<='C')&&(y>='A'&&y<='C'))||
			   ((x=='D'||x=='F')&&(y=='D'||y=='F'))){
				cout<<1;
				if(abs(x-y)!=1)cout<<0;
				else cout<<1;
		   }
			   
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	
	
}//finish!
