#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,i1,j1;
	string s1,s2,S1,S2;
	string m[5]={"A","B","C","D","F"};
	cin >>c1>>s1>>c2>>s2;
	S1=s1[2];
	S2=s2[2];
	if(c1==c2){
		for (int i=0;i<=4;i++){
			if(S1==m[i]){
				i1=i;
			}
		}
		for (int j=0;j<=4;j++){
			if(S2==m[j]){
				j1=j;
			}
		}
		cout <<1<<(s1[0]==s2[0]&&s1[1]==s2[1])<<((i1<=2&&j1<=2)||(i1>2&&j1>2));
		}
		if(S1=="A"){
			cout <<(i1+1==j1);
		}
		else{
			if(S1=="F"){
				cout <<(i1-1==j1);
			}
			else{
				cout <<(((i1<=2&&j1<=2)||(i1>2&&j1>2))&&(i1+1==j1)||(i1-1==j1));
			}
	}
	if(c1!=c2){
		cout <<0<<0<<0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
