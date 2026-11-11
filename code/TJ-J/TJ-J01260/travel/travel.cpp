#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool t1=(a==c),
		 t2=(b.substr(0,2)==d.substr(0,2)),
		 t3=(b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'),
		 t4=(b[2]-d[2]==1||b[2]-d[2]==-1);
	cout<<(t1);
	cout<<(t1&&t2);
	cout<<(t1&&t2&&t3);
	cout<<(t1&&t2&&t3&&t4);
	cout<<endl;
	return 0;
}

