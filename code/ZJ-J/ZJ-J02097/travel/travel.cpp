#include <bits/stdc++.h>
using namespace std;
string n,m,n1,m1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	long long n2=0,m2=0,f=0;
	char n3=0,m3=0;
	cin>>n>>n1>>m>>m1;
	n2=(n1[0]-'0')*10+n1[1]-'0';
	m2=(m1[0]-'0')*10+m1[1]-'0';
	n3=n1[2];
	m3=m1[2];
	if(n==m){
		cout<<1;
		if(n2==m2){
			cout<<1;
			if((n3>='A'&&n3<='C'&&m3>='A'&&m3<='C')||(n3>='D'&&n3<='E'&&m3>='D'&&m3<='E')){
				cout<<1;
				if(n3==n2-1||n3==n2+1)
				    cout<<1;
				else
				    f=1;
			}
			else
			    f=2;
		}
		else
			f=3;
	}
	else
		f=4;
	for(int i=1;i<=f;i++)
	    cout<<0;
	return 0;
}
