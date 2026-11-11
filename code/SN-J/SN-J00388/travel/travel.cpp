#include<bits/stdc++.h>
using namespace std;
int main(){
	//A:65
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string n,m;
	cin>>x>>n>>y>>m;
	//cout<<x<<n<<y<<m;
	if(x!=1&&x!=16&&y!=1&&y!=16){
		if(x==y){
			if(n[0]+n[1]==m[0]+m[1]){
				if(n[2]+1==m[2]+1-1){
					if(n[2]+1-1!=67){
						cout<<"1111";
					}
					else{
						cout<<"1100";
					}
				}
				else if(n[2]+1-1==m[2]+1){
					if(m[2]+1-1!=67){
						cout<<"1111";
					}
					else{
						cout<<"1100";
					}
				}
				else if(n[2]+2==m[2]+1-1){
					cout<<"1110";
				}
				else if(m[2]+2==n[2]+1-1){
					cout<<"1110";
				}
				else{
					cout<<"0000";
				}
			}
			else{
				cout<<"1000";
			}
		}
		else{
			cout<<"0000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
