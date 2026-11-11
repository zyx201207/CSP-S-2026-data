#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string x,y,xx,yy;
	cin>>x>>y>>xx>>yy;
	if(x!=xx){
		cout<<"0000";
	}
	else{
		int sum1,sum2;
		sum1=(y[0]-'0')*10+y[1]-'0';
		sum2=(yy[0]-'0')*10+yy[1]-'0';
		if(sum1!=sum2){
			cout<<"1000";
		}
		else{
			char l1,l2;
			l1=y[2],l2=yy[2];
			if(l1<=67&&l2>=67||l2>=67&&l2<=67){
				cout<<"1100";
			}
			else{
				int l3,l4;
				l3=l1;
				l4=l2;
				if(abs(l3-l4)!=1){
					cout<<"1110";
				}
				else{
					cout<<"1111";
				}
			}
		}
	}
}  
