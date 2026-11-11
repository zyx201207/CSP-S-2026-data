#include<bits/stdc++.h>
using namespace std;
int a,b,m,n,s;
int main(){
freopen("and.in","r",stdin);
freopen("and.ans","w",stdout);
//我真求了，时间都花在第四题上了，人做的？ 
cin>>m>>n;
for(int i=0;i<m;i++){
	cin>>s;
	a=max(a,s);
}
cout<<a;
fclose(stdin);
fclose(stdout);
}
