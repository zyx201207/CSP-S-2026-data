#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",sidin);
	freopen("travel.out","w",sidout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 && c1!=01 && c1!=16 && c2!=01 && c2!=16) cout<<"1";
	for (int i=1;i<s1.size();i++){
		for (int j=1;j<s2.size();j++){
			if (i==j && i+1==j+1){
				cout<<"1";
			}
			else cout<<"0";                                                                 
		}
    }
    for (int i=1;i<=s1.size();i++){                                                                                                                                                                                                                                                                                                                    
		for (int j=1;j<=s2.size();j++){
			if (i+s1.size()-j+s2.size()==1 || j+s2.size()-i+s1.size()==1){
				cout<<"1";
			}
			else cout<<"0";
		}
	}
	return 0;
}