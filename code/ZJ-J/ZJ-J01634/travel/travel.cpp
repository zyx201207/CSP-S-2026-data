#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	string b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int c1=0,c2=0,c3=0,c4=0,a4,b4;
	if(a1==b1){
		c1=1;
		char a3=a2[2];
		char b3=b2[2];
		if(a3<='C')a4=1;
		if(b3<='C')b4=1;
		int f=0;
		for(int i=0;i<=1;i++){
			if(a2[i]!=b2[i])f=1;
		}
		if(f==0){
			c2=1;
			if(a4==b4){
				c3=1;
				if(a3==b3+1||a3+1==b3){
					c4=1;
				}
			}
		}
	}
	cout<<c1<<c2<<c3<<c4;
}
