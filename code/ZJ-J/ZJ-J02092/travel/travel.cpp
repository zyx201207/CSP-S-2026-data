#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans1=0,ans2=0,ans3=0,ans4=0;

bool check(string x,string y){
	int p1 = x[2] - 'A';
	int p2 = y[2] - 'A';
	if((p1 <= 2 && p2 <= 2)||(p1 > 2 && p2 > 2)) return 1;
	else return 0;
}

bool check1(char x,char y){
	if(x <= 'C'){
		if(abs(x - y) == 1) return 1;
		else return 0;
	}else{
		if(y <= 'C') return 0;
		else return 1;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		ans1 = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			ans2 = 1;
			if(check(s1,s2)){
				ans3 = 1;
				if(check1(s1[2],s2[2])) ans4 = 1;
			}
		}
	}
	printf("%d%d%d%d",ans1,ans2,ans3,ans4);

	return 0;
}
