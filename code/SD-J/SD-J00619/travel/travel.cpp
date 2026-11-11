#include<bits/stdc++.h>
using namespace std;
string rt,rs,xt,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>rt>>rs>>xt>>xs;
	int r=(rt[0]-'0')*10+rt[1]-'0';
	int x=(xt[0]-'0')*10+xt[1]-'0';
	int R=(rs[0]-'0')*10+rs[1]-'0';
	int X=(xs[0]-'0')*10+xs[1]-'0';
	if(r!=x){
		cout<<"0000";
	}else{
		cout<<'1';
		if(R!=X){
			cout<<"000";
		}else{
			cout<<'1';
			if((rs[2]>='A'&&rs[2]<='C'&&xs[2]>='A'&&xs[2]<='C') || (rs[2]>='D'&&rs[2]<='F'&&xs[2]>='D'&&xs[2]<='F')){
				cout<<'1';
				int kr=rs[2]-'A';
				int kx=xs[2]-'A';
				int maxx=max(kr,kx);
				int minn=min(kr,kx);
				if(rs[2]>='C' && rs[2]<='D' &&xs[2]>='C' && xs[2]<='D') cout<<'0';
				else if(maxx-minn==1 ) cout<<'1';
				else cout<<'0';		
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
