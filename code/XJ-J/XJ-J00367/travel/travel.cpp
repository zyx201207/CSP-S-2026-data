#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int clen1 = c1.size();
	int ren = 0;
	
	for(int i=0;i<clen1;i++){
		if(c1[i]==c2[i]){
			ren += 1;
			if(ren==2){
				cout << "1";
			}
			else if(i==2&&ren!=2){
				cout << "0";
			}
		}
	}	
	
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			cout << "1";
		}
		else if(s1[i]!=s2[i]){
			cout << "1";
		}
	}
	
	cout << "0";
	
	return 0;
}