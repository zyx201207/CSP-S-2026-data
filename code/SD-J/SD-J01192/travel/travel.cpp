#include <bits/stdc++.h> 
using namespace std;

struct seat{
	int hang;
	int lie;
};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	seat s1,s2;
	scanf("%d %d%c %d %d%c",&c1,&s1.hang,&s1.lie,&c2,&s2.hang,&s2.lie);
	s1.lie -= 65;
	s2.lie -= 65;
	if(c1!=c2){
		cout <<"0000";
	}
	else{
		cout << "1";
		if(s1.hang!=s2.hang){
			cout << "000";
		}
		else{
			cout << "1";
			if(!((s1.lie<=2&&s2.lie<=2)||(s1.lie>2&&s2.lie>2))){
				cout << "00";
			}
			else{
				cout << "1";
				if(abs(s1.lie-s2.lie)!=1){
					cout << "0";
				}
				else{
					cout << "1";
				}
			}
		}
	}
	//printf("%d %d %d %d %d %d",c1,s1.hang,s1.lie,c2,s2.hang,s2.lie);
	return 0;
}
