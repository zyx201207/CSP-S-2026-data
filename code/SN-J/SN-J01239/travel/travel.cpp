#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int flag=0,fa=0,f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		fa=1;
	}else{
		cout<<0;
	}
	if(fa==1&&a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
		flag=1;
	}else{
		cout<<0;
	}
	if(flag==1&&(a2[2]<='C'&&b2[2]<='C'||a2[2]>='D'&&b2[2]>='D')){
		cout<<1;
		f=1;
	}else{
		cout<<0;
	}
	if(f==1&&(a2[2]==b2[2]-1||a2[2]==b2[2]+1||a2[2]=='D'&&b2[2]=='F'||a2[2]=='F'&&b2[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
