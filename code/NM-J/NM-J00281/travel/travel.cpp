#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
bool c[4]={0,0,0,0};
int d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		c[d]=1;
		d++;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
		c[d]=1;
		d++;
		if(a1[2]>'C'&&b1[2]>'C'){
		c[d]=1;
		d++;
		if(a1[2]-b1[2]==2||a1[2]-b1[2]==-2){
		c[d]=1;
		d++;
		}
			}
		else if(a1[2]<='C'&&b1[2]<='C'){
		c[d]=1;
		d++;
		if(a1[2]-b1[2]==1||a1[2]-b1[2]==-1){
		c[d]=1;
		d++;
		}
		}
	}
	}
	for(int i=0;i<4;i++){
		cout<<c[i];
		}
	
	return 0;
}
