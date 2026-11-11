#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,pos1,c2,pos2;
	ll r1=0,r2=0;
	cin>>c1>>pos1>>c2>>pos2;
	r1=(pos1[0]-'0')*10+(pos1[1]-'0');
	r2=(pos2[0]-'0')*10+(pos2[1]-'0');
	char p1=pos1[pos1.size()-1];
	char p2=pos2[pos2.size()-1];
	bool q1=false,q2=false,q3=false,q4=false;
	if(c1==c2){
		q1=true;
		if(r1==r2){
			q2=true;
			if((p1<='C'&&p2<='C')||(p1>='D'&&p2>='D')){
				q3=true;
				ll num1=(ll)p1-'A';
				ll num2=(ll)p2-'A';
				if(num1==num2+1||num2==num1+1){
					q4=true; 
				}
			}
		}
	}
	cout<<q1<<q2<<q3<<q4<<endl;
	return 0;
} 
