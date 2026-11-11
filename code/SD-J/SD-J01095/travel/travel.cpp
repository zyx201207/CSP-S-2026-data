#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
string c1,s1,c2,s2,p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	char z1=s1[2];
	char z2=s2[2];
	char near1=s1[2];
	char near2=s2[2];
	if((z1=='F')||(z1=='D')){
		z1='0';
	}
	else{
		z1='1';
	}
	if((z2=='F')||(z2=='D')){
		z2='0';
	}
	else{
		z2='1';
	}
    for(int i=0;i<=1;i++){
    	p1+=s1[i];
    	p2+=s2[i];
	}
	if(c1==c2){
		if(p1==p2){
			if(z1==z2){
				if(((near1+1==near2)||(near1-1==near2))&&((near1!='D'||near1!='C')&&(near1!='D'||near1!='C'))){
					cout<<"1111"<<endl;
				}
				else{
					cout<<"1110"<<endl;
				}
			}
			else{
				cout<<"1100"<<endl;
			}
		}
		else{
			cout<<"1000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
} 
