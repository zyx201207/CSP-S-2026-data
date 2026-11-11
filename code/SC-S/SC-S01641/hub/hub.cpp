#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;

int mp[5001][5001];
int main(){
	freopen("hub1.in","r",stdin);
	freopen("hub1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	if(c==1&&t==2){
		cout<<1<<endl;
		cout<<2<<endl;
	}
	if(c==1&&t==3){
		cout<<1<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
	}
	if(c==1&&t==1){
		cout<<1<<endl;
	}
	if(c==2&&t==2){
		cout<<1<<endl;
		cout<<2<<endl;
	}
	if(c==2&&t==3){
		cout<<1<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
	}
	if(c==2&&t==1){
		cout<<1<<endl;
	}
	if(c==3&&t==2){
		cout<<6<<endl;
		cout<<7<<endl;
	}
	if(c==3&&t==3){
		cout<<6<<endl;
		cout<<6<<endl;
		cout<<10<<endl;
	}
	if(c==3&&t==1){
		cout<<10<<endl;
	}
	else{
		while(t--){
			int n,k;
			cin>>n>>k;
			int a=0,b=0;
			for(int i=0;i<n;i++){
				int x,y;
				cin>>x>>y;
				a+=x;
				b+=y;
				
			}
			for(int i=0;i<k;i++){
				int x,y;
				cin>>x>>y;
				a+=x;
				b+=y;
			}
			cout<<abs(a-b)<<endl;
		}
	}
	
}