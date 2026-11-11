#include<bits/stdc++.h>
using namespace std;
char q1,w1,e1,r1,t1,q2,w2,e2,r2,t2;
int t3,t4,qw=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q1>>w1>>e1>>r1>>t1>>q2>>w2>>e2>>r2>>t2;
	t3=t1-'A';
	t4=t2-'A';
	if(q1==q2&&w1==w2){
		cout<<"1";
		if(e1==e2&&r1==r2){
			cout<<"1";
			if(t3<3&&t4<3||t3>2&&t4>2){
				cout<<"1";
				if(t3<3&&t4<3){
					if(t3-t4==1||t4-t3==1){
					
						cout<<"1";
						qw++;
					}
				}
				if(t3>2&&t4>2){
					if(t3-t4==2||t4-t3==2){
						cout<<"1";
						qw++;	
					}
				}
				if(qw==0)cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
