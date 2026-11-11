#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,sx,a,ax;
	int n[10]={0};
	cin>>s>>sx>>a>>ax;
	if(s!=a){
		cout<<"0000";
		return 0;
	}
	string d="",f="";
	d+=sx[0]+sx[1];
	f+=ax[0]+ax[1];
	if(d!=f){
		cout<<"1000";
		return 0;
	} 
	int q=sx[2]-'A',w=ax[2]-'A';
	if((q<=2&&w>=3)||(q>=3&&w<=2)){
		cout<<"1100";
		return 0;	
	}
	n[q]++;
	n[w]++;
	if((n[0]==1&&n[1]==1)||(n[1]==1&&n[2]==1)||(n[3]==1&&n[5]==1)){
		cout<<"1111";
	}
	else{
		cout<<"1110";
	}
	return 0;
}
