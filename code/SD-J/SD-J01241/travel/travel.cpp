#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt;
string a,aa,b,bb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
		cnt++;
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			cout<<1;
			cnt++;
			char x=aa[2],y=bb[2];
			if(x>y){
				char t=x;
				x=y;
				y=t;
			}
			if(!(x<='C'&&y>='D')){
				cout<<1;
				cnt++;
				if((x=='D'&&y=='F')||y-x==1){
					cout<<1;
					cnt++;
				}
			}
		}
	}
	for(int i=cnt+1;i<=4;++i) cout<<0;
	return 0;
} 
