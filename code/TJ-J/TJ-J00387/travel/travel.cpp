#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    cin >> c1>> s1>>c2>>s2;
    if(c1 <= 17 && c1!=01 && c1!=16 &&c2 <= 17 && c2!=01 && c2!=16){
    	if(c1 == c2){
    		cout << '1';
		}
		if(s1 == s2){
			cout<<'1';
		}
	}
    return 0;
}
