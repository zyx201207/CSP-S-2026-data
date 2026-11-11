//马澔辰 西安市第四十二中学 SN-J00741 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a1,a2;
	cin >> s1 >> a1 >> s2 >> a2;
	if(s1==s2){
		cout << 1;
	}else{
		cout << 0;
	}
	for(int i=0;i<a1.size();i++){
		int flag=0;
		for(int j=0;j<a1.size()-1;j++){
			if(a1[j]!=a2[j]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout << 0;
		}else{
			cout << 1;
		}
		if(((a1[a1.size()]=='A'||a1[a1.size()]=='B'||a1[a1.size()]=='C')||(a1[a1.size()]=='D'||a1[a1.size()]=='F'))&&((a2[a2.size()]=='A'||a2[a2.size()]=='B'||a2[a2.size()]=='C')||(a2[a2.size()]=='D'||a2[a2.size()]=='F'))){
			cout << 1;
		}else{
			cout << 0;
		}
	}
}
