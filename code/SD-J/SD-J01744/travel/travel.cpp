#include<iostream>
#include<cstdio>
using namespace std;
string tra,trb,sea,seb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>tra>>sea>>trb>>seb;
	if(tra!=trb){
		cout<<"0000";
	}
	else{
		string pa=sea.substr(0,2),pb=seb.substr(0,2);
		if(pa!=pb){
			cout<<"1000";
		}
		else{
			char sa=sea[2],sb=seb[2];
			if((sa<='C'&&sb>='D')||(sa<='C'&&sb>='D')){
				cout<<"1100";
			}
			else{
				if((int)sb==(int)sa+1||(int)sb==(int)sa-1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
		}
	}
	return 0;
}
