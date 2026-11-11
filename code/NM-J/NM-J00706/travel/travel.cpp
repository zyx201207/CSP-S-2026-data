#include <iostream>
#include <cstdio>
#include <cstring>	
#include <vector>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string d;
	cin>>a>>b>>c>>d;
	string ve;
	string vec;
	string vec1;
	string vec2;
	if(a==c){
		for(int i=0;i<b.size();i++){
			if(b[i]<='9'&&b[i]>='0'){
				ve.push_back(b[i]);
			}else{
				vec.push_back(b[i]);
			}
		}
		for(int i=0;i<d.size();i++){
			if(b[i]<='9'&&b[i]>='0'){
				vec1.push_back(d[i]);
			}else{
				vec2.push_back(d[i]);
			}
		}
		if(ve==vec1){
			if(vec[0]<='C'&&vec2[0]<='C'){
				if(vec[0]=='B'){
					cout<<"1111";
					
				}else if(vec2[0]=='B'){
					cout<<"1111";
					
				}else{
					cout<<"1110";
					
				}
			}else if(vec[0]<='F'&&vec2[0]<='F'&&vec[0]>='D'&&vec2[0]<='D'){
				cout<<"1111";
			}else{
				cout<<"1100";
				
			}
		}else{
			cout<<"1000";
			
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
