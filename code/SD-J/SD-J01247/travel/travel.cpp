#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if((int)(s1[0])*10+(int)s1[1]==(int)(s2[0])*10+(int)s2[1]){
			cout<<"1";
			int w1=s1[2]-'A'+1,w2=s2[2]-'A'+1;
			if(w1>w2)	swap(w1,w2);
			if(w1==1){
				if(w2==2)	cout<<"11";
				else if(w2==3)	cout<<"10";
				else	cout<<"00";
			}
			else if(w1==2){
				if(w2==3)	cout<<"11";
				else	cout<<"00";
			}
			else if(w1==3)	cout<<"00";
			else if(w1==4){
				if(w2==6)	cout<<"11";
			}
		}
		else	cout<<"000";
	}
	else	cout<<"0000";
	return 0;
}

