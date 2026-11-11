#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int q1,q2,q3,q4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		q1++;
	}
	if(a1[1]==b1[1]&&a1[0]==b1[0]&&a==b){
		q2++;
	}
	if(q1==1&&q2==1){
		if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'){
			if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
				q3++;
			}
		}
		if(a1[2]=='D'||a1[2]=='F'){
			if(b1[2]=='D'||b1[2]=='F'){
				q3++;
			}
		}
	}
	if(q3==1){
		if(a1[2]=='F'&&b1[2]=='D'){
			q4++;
			cout<<q1<<q2<<q3<<q4;
			return 0;
		}
		if(a1[2]=='D'&&b1[2]=='F'){
			q4++;
			cout<<q1<<q2<<q3<<q4;
			return 0;
		}
		if(a1[2]-b1[2]==1&&a1[2]!='D'){
			q4++;
			cout<<q1<<q2<<q3<<q4;
			return 0;
		}
		if(b1[2]-a1[2]==1&&b1[2]!='D'){
			q4++;
			cout<<q1<<q2<<q3<<q4;
			return 0;
		}
	}
	return 0;
}
