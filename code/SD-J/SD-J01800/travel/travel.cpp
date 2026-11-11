#include <bits/stdc++.h>
using namespace std;

int pai(string s1,string s2){
	string x = "";
	string y = "";
	for(int i = 0;i <= 1;i++){
		x += s1[i];
		y += s2[i];
	}
	if(x == y) return 1;
	return 0;
}

int ce(int x,int y){
	if(x <= 67 && y <= 67) return 1;
	return 0;
}

int ai(int x,int y){
	int t;
	if(x > y) t = x - y;
	else t = y - x;
	
	if(t == 1) return 1;
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2; 
	cin>>c1>>s1>>c2>>s2;
	
	if(c1 == c2){  
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(pai(s1,s2) == 1){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	int x,y;
	x = (int)s1[2];
	y = (int)s2[2];
	
	if((x == 68 && y == 69) || (x == 69 && y == 68)){
		cout<<"11";
		return 0;
	}
	
	if(ce(x,y) == 1){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(ai(x,y) == 1){
		cout<<1;
	}
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
