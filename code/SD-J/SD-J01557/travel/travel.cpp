#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ch1,ch2,li1,li2;
	ch1=(c1[0]-'0')*10+(c1[1]-'0');
	ch2=(c2[0]-'0')*10+(c2[1]-'0');
	li1=(s1[0]-'0')*10+(s1[1]-'0');
	li2=(s2[0]-'0')*10+(s2[1]-'0');
	if(ch1!=ch2){
		cout<<"0000";
	}else{
		if(li1!=li2){
			cout<<1000;
		}else{
			char a=s1[2],b=s2[2];
			if(!( (a<='C'&&b<='C')||((a>'C'&&b>'C')) )){
				cout<<1100; 
			}else{
				if(max(a-b,b-a)==1) cout<<1111;
				else cout<<1110;
			}
		}
	}
	return 0;
}
