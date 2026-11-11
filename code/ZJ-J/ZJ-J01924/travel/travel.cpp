#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
int kkk(char x){
	if(x=='F'){
		return 5;
	}else{
		return x-'A'+1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			int a1=kkk(s1[2]),a2=kkk(s2[2]);
			if(a1<=3 and a2<=3 or a1>3 and a2>3){
				cout<<1;
				if(abs(a1-a2)==1){
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