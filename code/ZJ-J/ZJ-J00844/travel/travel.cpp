#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char a1=s1[0],a2=s2[0],b1=s1[1],b2=s2[1],d1=s1[2],d2=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		if(a1==a2 && b1==b2){
			cout<<1;
			if(d1=='A' && d2=='C' || d1=='C' && d2=='A'){
				cout<<"10";
				return 0;
			}else if(d1=='D' && d2=='F' || d1=='F' && d2=='D' || d1=='A' && d2=='B' || d1=='B' && d2=='A' || d1=='B' && d2=='C' || d2=='C' && d1=='B'){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}
	
	return 0;
}
