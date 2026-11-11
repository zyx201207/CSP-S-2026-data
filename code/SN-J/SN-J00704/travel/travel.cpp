//ÕÅ²Ó 12ÖĞÑ§ SN-J00704 
#include <bits/stdc++.h>
using namespace std;
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdin);
int c1,s1,c2,s2,c3;
int ans1,ans2;
int a1;
int change(string s){
	int a1;
	cin >> a1;
	int ans=0;
	for(int i=1;i<=a1;i++){
		int num1=((s[i])-int'0');
		if(num1>=0 && num1<=9) ans=ans*10;
		else  break;
	}
}
int main(){
	bool num=true;
	cin >> c1 >> s1 >> c2 >> s2;
	a1=chnagess(c1),changess(s1),changess(c2),changess(s2);
	int a,b;
	a=(c2[2]-(int'A')+1;
	b=(c3[2]-(int'A')+1;
	if(a1=ans1 && num) cout << 1;
	else{
		cout << 0000;
		num=1;
	}
	//fclose(stdin);
	//fclose(stdin); 
	return 0;
}
