#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int t1=(c1[0]-'0') *10+(c1[1]-'0');
	int t2=(c2[0]-'0') *10+(c2[1]-'0');
	if(t1==t2) {
		cout<<1;
		int t3=(s1[0]-'0') *10+(s1[1]-'0');
	    int t4=(s2[0]-'0') *10+(s2[1]-'0');
	    if(t3==t4){
	    	cout<<1;
	    	int cnt1=s1[2]-'A';
	    	int cnt2=s2[2]-'A';
	    	if((cnt1<3&&cnt2<3)||(cnt1>3&&cnt2>3)){
	    		cout<<1;
	    		if(abs(cnt1-cnt2)==1) cout<<1;
	    		else cout<<0;
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
