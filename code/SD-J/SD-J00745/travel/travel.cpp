#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a1>>a2;
	cin>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<'1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<'1';
			if(('D'<=a2[2])==('D'<=b2[2])){
				cout<<'1';
				if(int(a2[2])-int(b2[2])==-1||int(a2[2])-int(b2[2])==1){
					cout<<'1';
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}
