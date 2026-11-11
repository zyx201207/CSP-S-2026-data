#include<bits/stdc++.h>
using namespace std;
string cx,sx,cr,sr;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx)cout<<"0000";
	else{
		cout<<'1'; 
		if(sr[0]+sr[1]!=sx[0]+sx[1])cout<<"000";
		else{
			cout<<'1';
			if(sr[2]>='D'&&sx[2]>='D')cout<<"11";
			else if(sr[2]<='C'&&sx[2]<='C'){
				cout<<'1';
				if(sr[2]-sx[2]<=1)cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
