#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	int n1=cr.size(),n2=cx.size();
	bool flag=true;
	for (int i=0;i<n1;i++){
		if (cr[i]!=cx[i]){
			flag=false;
			break;
		}
	}
	if (flag) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if (sr[0]==sx[0]&&sr[1]==sx[1]){
		cout<<1;
		if ((sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C')){
			cout<<1;
			int sum=sr[2]-sx[2];
			if (abs(sum)==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if ((sr[2]=='D'||sr[2]=='F')&&(sx[2]=='D'||sx[2]=='F')){
			cout<<1<<1;
		}
		else{
			cout<<"00";
		}
		return 0;
	}
	else{
		cout<<"000";
		return 0;
	}
}
