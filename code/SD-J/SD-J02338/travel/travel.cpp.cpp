#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,sr,sx,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		cout<<"0000"<<endl;return 0;
	}
	for(int i=0;i<=2;i++){
		if(i==2){
			r=s1[i];
			x=s2[i];
			break;
		}
		sr+=s1[i];
		sx+=s2[i];
	}
	if(sr==sx) cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(r=="A"||r=="B"||r=="C"){
		if(x=="A"||x=="B"||x=="C"){
			cout<<1;
			if((r=="A"&&x=="C")||r=="C"&&x=="A"){
				cout<<0<<endl;
				return 0;
			}
			cout<<1<<endl;
			return 0;
		}	
	}
	else if((r=="D"&&x=="F")||(r=="F"&&x=="D")){
		cout<<"11"<<endl;
		return 0;
	}
	cout<<"00"<<endl;
	return 0;
} 
