#include <bits\stdc++.h>
using namespace std;
int main() {
	freopen("travel.in,"r",stdin);
	freopen("travel.out,"w",stdout); 
	int c1;
	int s1;
	int c2;
	int s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<=2;i++){
			if(c1[i]==c2[i]){
				cout<<1;
			}
		}
	}
	else{
		cout<<000;
	}
	return 0;
}
