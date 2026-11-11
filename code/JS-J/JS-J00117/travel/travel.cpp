#include<bits/stdc++.h>
using namespace std;
int a,b;
string q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>a>>q>>b>>w;
	if(a==b){
		cout<<1;
		if(q[0]==w[0]&&q[1]==w[1]){
			cout<<1;
			char z=q[2],x=w[2];
			if(!((z<='C')^(x<='C'))){
				cout<<1;
				if(z>x)swap(z,x);
				if(x<='C'&&x==char(z+1))cout<<1;
				else cout<<(x=='F'&&z=='D');
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
