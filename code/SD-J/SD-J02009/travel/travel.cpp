#include<bits/stdc++.h>
using namespace std;
string ca,cb,cc,cd,s,ss;
bool a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>cb>>cc>>cd;
	for(int i=0;i<=1;i++){
		s+=cb[i];
		ss+=cd[i];
	}
	if(ca==cc){
		a[1]=1;
		if(s==ss){
			a[2]=1;
			if((cb[2]>='D'&&cd[2]<='F'&&cb[2]<='F'&&cd[2]>='D')||(cd[2]>='A'&&cd[2]<='C'&&cb[2]>='A'&&cb[2]<='C')){
				a[3]=1;
				if((cd[2]-'A')==(cb[2]-'A')+1||(cb[2]-'A')==(cd[2]-'A')+1){
					a[4]=1;
				}
			}
		}
		
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
} 
