#include<bits/stdc++.h>
using namespace std;
int a[5];
bool check(string s1,string s2){
	return (s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a[1]=1;
	if(a[1]&&(s1[1]==s2[1]&&s1[0]==s2[0]))a[2]=1;
	if(a[2]&&check(s1,s2))a[3]=1;
	if(a[3]&&(s1[2]-1==s2[2]||s1[2]+1==s2[2]))a[4]=1;
	for(int i=1;i<=4;i++)cout<<a[i];cout<<"\n";
	return 0;
}
