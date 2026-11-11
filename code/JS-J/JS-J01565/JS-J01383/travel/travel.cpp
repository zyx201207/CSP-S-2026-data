#include<bits/stdc++.h>
#define int long long
using namespace std;
int x1,x2,x3,x4;
string a,a1,b,b1;
bool tp(string x,string y){
	int a1=(x[0]-'0')*10+(x[1]-'0');
	int b1=(y[0]-'0')*10+(y[1]-'0');
	return (a1==b1&&a==b);
}
bool tc(string x,string y){
	int t1,t2;
	t1=x[x.size()-1]-'A';
	t2=y[y.size()-1]-'A';
	if(t1>t2) swap(t1,t2);
	if(t2-t1>2) return false;
	else if(t1==2&&t2==3) return false;
	else if(tp(x,y)==0) return false;
	else return true;
}
bool xl(string x,string y){
	int t1,t2;
	t1=x[x.size()-1]-'A';
	t2=y[y.size()-1]-'A';
	if(t1>t2) swap(t1,t2);
	if(t1==3&&t2==5) return true;
	else if(t2-t1>1) return false;
	else if(t1==2&&t2==3) return false;
	else if(tc(x,y)==0) return false;
	else return true; 
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b) x1=1;
	if(tp(a1,b1)) x2=1;
	if(tc(a1,b1)) x3=1;
	if(xl(a1,b1)) x4=1;
	cout<<x1<<x2<<x3<<x4;
	return 0;
}
