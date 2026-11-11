//JiangMingrui xian89zhong SN-J00643
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	cout << 1;
	else{	
	cout << 0<<0<<0 << 0;
	return 0;}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	cout << 1;
	else{
	cout << 0 << 0 << 0;
	return 0;}
	
	if(s1[2]<68&&s2[2]<68)
	cout << 1;
	else if(s1[2]>67&&s2[2]>67)
	cout << 1;
	else{
	cout << 0 << 0;
	return 0;}
	
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
	cout << 1;
	else
	cout << 0;
	
	return 0;
}
