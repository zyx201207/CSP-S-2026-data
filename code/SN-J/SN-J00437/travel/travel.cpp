#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int z1=(int)(s1[0]-'0')*10+(int)(s1[1]-'0'),z2=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
	char a1=s1[2],a2=s2[2];
	if(c1==c2){
		cout<<1;
	    if(z1==z2){
	    	cout<<1;
	    	if((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D')){
	    		cout<<1;
	    		if(abs(a1-a2)==1){
	    			cout<<1;
				}else{
					cout<<"0";
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
