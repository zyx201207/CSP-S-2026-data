#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
//02 01C 02 01D
//02 01A 02 01B
//hello!
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int zuoweiR=(s1[0]-'0')*10+(s1[1]-'0');
		int zuoweiX=(s2[0]-'0')*10+(s2[1]-'0');
        char R=s1[2],X=s2[2];
		if(zuoweiR!=zuoweiX){
			cout<<0<<0<<0<<endl;
			return 0;
		}
		cout<<1;
		if(R>='A'&&R<='C'&&X>='A'&&X<='C')
			cout<<1;
		else if(R>='D'&&R<='F'&&X>='D'&&X<='F')
			cout<<1;
		else{
			cout<<0<<0<<endl;
			return 0;
		}
		if(R+1==X||X+1==R){
			cout<<1<<endl;
		}
		else cout<<0<<endl;
    }
	else cout<<0<<0<<0<<0<<endl;
	return 0;
}
