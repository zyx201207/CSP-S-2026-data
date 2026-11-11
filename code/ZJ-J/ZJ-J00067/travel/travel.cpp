#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int x,y,a,b;
	char f,g;
	cin>>x>>a>>f>>y>>b>>g;
	if(g == 'F'){
		g = 'E';
	}
	if(f == 'F'){
		f = 'E';
	}
	if(x == y){
		cout<<1;
		if(a == b){
			cout<<1;
			if((f <= 'C'&&g <= 'C')||(f >= 'D'&&g >= 'D')){
				cout<<1;
				if(abs(f-g) == 1&&(f != 'C'||f != 'D'||g != 'C'||g != 'D')){
					cout<<1;
				}else{
					cout<<0;
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
