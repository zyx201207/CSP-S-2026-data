#include<bits/stdc++.h>
using namespace std;
int n,m;
char a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>b>>c>>m>>d>>e>>f;
//	cout<<n<<a<<b<<c<<m<<d<<e<<f;
	if(n==m){
		cout<<1;
		if(a==d&&b==e){
			cout<<1;
			if(c<'D'&&f<'D'){
				cout<<1;
				if(f-c==1||c-f==1)cout<<1<<endl;
				else cout<<0<<endl;
			}
			else if(c>'C'&&f>'C'){
				cout<<"11"<<endl;
			}
			else cout<<"00"<<endl;
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
}
