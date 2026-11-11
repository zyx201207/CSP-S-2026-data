#include<bits/stdc++.h>
using namespace std;
char a[5],wa[5],b[5],wb[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a[1]>>a[2]>>wa[1]>>wa[2]>>wa[3];
	cin>>b[1]>>b[2]>>wb[1]>>wb[2]>>wb[3];
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<"1";
		if(wa[1]==wb[1]&&wa[2]==wb[2]){
			cout<<"1";
			int sa=int(wa[3]-'A'),sb=int(wb[3]-'A');
			if((sa>=3&&sb>=3)||(sa<3&&sb<3)){
				cout<<"1";
				if(sa==sb+1||sa+1==sb){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
