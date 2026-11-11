#include<bits/stdc++.h>
using namespace std;
int a,c,cnt; 
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		cnt++;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			cnt++;
			if(b[2]+d[2]!=135){
				cout<<"1";
				cnt++;
				if(d[2]-b[2]==1||d[2]-b[2]==-1){
					cout<<"1";
					return 0;
				}
			} 
		} 
	}
	for(int i=0;i<4-cnt;i++) cout<<"0";
	return 0;
} 
