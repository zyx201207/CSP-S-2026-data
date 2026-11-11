#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[6],s2[6];
char wei1,wei2;
int main(){
 	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1;
    for(int i=1;i<=3;i++){
    	cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	wei1=s1[3];
	wei2=s2[3];
    wei1=wei1+'0';
    wei2=wei2+'0';
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[1]+'0'==s2[1]+'0'&&s1[2]+'0'==s2[2]+'0'){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(wei1<'D'+'0'&&wei2<'D'+'0'||wei1>'C'+'0'&&wei2>'C'+'0'){
			cout<<1;	
	}else{
		cout<<0<<0;
		return 0;
	}
	if(wei1!='D'+'0'&&wei2!='C'+'0'){
		if(wei1!='C'+'0'&&wei2!='D'+'0'){
			if(wei1=='D'+'0'&&wei2=='F'+'0'||wei2=='D'+'0'&&wei1=='F'+'0'){
				cout<<1;
			}else if(wei1+1==wei2||wei2+1==wei1){
				cout<<1;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
