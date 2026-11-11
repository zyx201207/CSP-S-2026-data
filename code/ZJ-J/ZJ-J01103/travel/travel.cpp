#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a_bh,b_bh,n,cnt=0;
	string a_zw,b_zw;
	n=a_zw.size();
	cin>>a_bh>>a_zw>>b_bh>>b_zw;
	if(a_bh==b_bh) cout<<"1";//Ïá 
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(a_zw[i]==b_zw[i])
			cnt++;
	}
	if(cnt==2) cout<<"1";
	else cout<<"0";//ÅÅ
	if(cnt==2){
		if(a_zw[2]<='C'&&b_zw[2]<='C'||a_zw[2]>'C'&&b_zw[2]>'C') cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";//²à
	if(cnt==2){
		if(a_zw[2]<='C'&&b_zw[2]<='C'||a_zw[2]>'C'&&b_zw[2]>'C'){
			if(abs(int(a_zw[2])-int(b_zw[2]))==1){
				cout<<"1";
			}
			else cout<<"0"; 
		}
		else cout<<"0";		
	}
	else cout<<"0";//ÁÚ	
	return 0;
} 
