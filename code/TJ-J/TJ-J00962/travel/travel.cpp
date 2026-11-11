#include<bits/stdc++.h>
#define int long long
using namespace std;

bool same(int l1,int l2){
	if(l1==0||l1==1||l1==2){
		if(l2==3||l2==5){
			return 0;
		}
	}else{
		if(l2==0||l2==1||l2==2){
			return 0;
		}
	}
	return 1;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		int r1=0,r2=0,l1=0,l2=0;
		r1+=s1[0]-'0';
		r1*=10;
		r1+=s1[1]-'0';
		l1+=s1[2]-'A';
		r2+=s2[0]-'0';
		r2*=10;
		r2+=s2[1]-'0';
		l2+=s2[2]-'A';
		if(r1==r2){
			cout<<'1';
			if(same(l1,l2)){
				cout<<'1';
				if((abs(l1-l2)==1)||(l1>2&&abs(l1-l2)==2)){
					cout<<'1';
				}else{
					cout<<'0';
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
