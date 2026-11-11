#include<bits/stdc++.h>
using namespace std;
long long a,s,f;
string q,e; 
int main(){
	preopen("and.in","r",stdin);
    preopen("and.out","w",stdout);
	cin>>a>>s>>f;
	for(int i=1;i<=a;i++){
		cin>>q;
	}cout<<q[f-1];
	return 0;
} //求求了，给我一点部分分也行啊！（哭） 
