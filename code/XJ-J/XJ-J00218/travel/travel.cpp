#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	int ans=0000;
	long long c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a='A' , b='B' , c='C' , d='D' , f='F' , e1=s1[0,2] , e2=s2[0,2];
	if (c1 == c2){
		ans += 1000;
	}if(s1[0,1] == s2[0,1] && s1[0,0] == s2[0,0]){
		ans += 100;
		if(e1 == a && e2 == b){
			ans += 11;
		}if(e1 == b && e2 == c){
			ans += 11;
		}if(e1 == d && e2 == f){
			ans += 11;
		}if(e1 == f && e2 == d){
			ans += 11;
		}if(e1 == c && e2 == b){
			ans += 11;
		}if(e1 == b && e2 == a){
			ans += 11;
		}if(e1 == c && e2 == a){
			ans += 10;
		}if(e1 == a && e2 == c){
			ans += 11;
		}
	}
	if (ans < 1000){
		cout << '0';
	}if (ans < 100){
		cout << '0';
	}if (ans < 10){
		cout << '0';
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
