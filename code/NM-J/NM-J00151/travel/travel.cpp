#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;

	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;

	if(c1==c2){
		cout<<1;

	}else {
	    cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else {
	    cout<<0;
	}

	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
		cout<<1;
		if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
			cout<<1;

		}else {
		    cout<<0;
		}
	}else{
		cout<<10;
	}


	return 0;
}
