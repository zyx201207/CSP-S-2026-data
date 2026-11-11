/*
PASSWORD : Trick||Treat!
11/1 ???
interesting
*/
#include <fstream>
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
string c1,c2,s1,s2;
short ans[5];
int main() {
	fin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			ans[2]=1;
			if(s1[2]=='D'){
				if(s2[2]=='F'){
					ans[3]=ans[4]=1;
				}
				else{
					ans[3]=ans[4]=0;
				}
			}
			else if(s1[2]=='A'){
				if(s2[2]=='B'||s2[2]=='C'){
					ans[3]=1;
					if(s2[2]=='B') {
						ans[4]=1;
					}
					else{
						ans[4]=0;
					}
				}
				else{
					ans[3]=ans[4]=0;
				}
			}
			else if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C'){
					ans[3]=ans[4]=1;
				}
				else{
					ans[3]=ans[4]=0;
				}
			}
			else if(s1[2]=='C'){
				if(s2[2]=='B'||s2[2]=='A'){
					ans[3]=1;
					if(s2[2]=='B') {
						ans[4]=1;
					}
					else{
						ans[4]=0;
					}
				}
				else{
					ans[3]=ans[4]=0;
				}
			}
			else if(s1[2]=='F'){
				if(s2[2]=='D'){
					ans[3]=ans[4]=1;
				}
				else{
					ans[3]=ans[4]=0;
				}
			}
		}
		else{
			ans[2]=ans[3]=ans[4]=0;
		}
	}
	else{
		ans[1]=ans[2]=ans[3]=ans[4]=0;
	}
	for(int i=1;i<=4;i++){
		fout<<ans[i];
	}
	fout<<endl;
}