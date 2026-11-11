#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string e="1111";
	string f="DFB";
	std::cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0] && b[1]==d[1]){
			if(b[2]==f[0] && d[2]==f[1]){
			e="1111";
			}else if(b[2]==f[1] && d[2]==f[0]){
				e="1111";
			}else if(b[2]==f[0] || b[2]==f[1] ||d[2]==f[0] ||d[2]==f[1]){
				e="1100";
			}else{
				if(b[2]==f[2] || d[2]==f[2]){
					e="1111";
				}else{
					e="1110";
				}
			}
		}else{
			e="1000";
		}
	}else{
		e="0000";
	}std::cout<<e;
	return 0;
}
