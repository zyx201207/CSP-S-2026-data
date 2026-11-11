#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int sum,l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 == c1){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	for(int i = 0;i<=2;i++){
		if(s2[i] == c2[i]){
			sum++;
		}
	}
	if(sum == 2){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(s2[2]<c2[2]){
		l = int(s2[2]);
		r = int(c2[2]);
	}else if(c2[2]<s2[2]){
		l = int(c2[2]);
		r = int(s2[2]);
	}
	if(l<=67&&r>=68){
		cout << "00";
		return 0;
	}else{
		cout << "1";
	}
	if(r-l==1&&r<=67||r-l==2&&r==70){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}