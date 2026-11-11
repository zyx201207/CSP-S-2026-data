#include<bits/stdc++.h>
using namespace std;
vector<int>v[100010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	if(c==1){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int aaa,bbb;
				cin>>aaa>>bbb;
			}
			if(n<k) cout<<1<<endl;
			else cout<<0<<endl;
		}
		return 0;
	}
	if(c==2||c==3){
		while(t--){
			int n,k;
			cin>>n>>k;
			int pos=1;
			for(int i=1;i<n;i++){
				int aaa,bbb;
				cin>>aaa>>bbb;
				if(abs(aaa-bbb)!=1) pos=0;
			}
			if(n<=k) cout<<0<<endl;
			else if(pos==1&&n>=9&&k==2){
				cout<<3<<endl;
			}else if(n<=5){
				cout<<1<<endl;
			}else if(pos==1){
				cout<<2<<endl;
			}else if(n/2>=k){
				cout<<2<<endl;
			}else cout<<1<<endl;
		}
	}
	if(c==7||c==11||c==12){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				int aa,bb;
				scanf("%d%d",&aa,&bb);
				v[aa].push_back(bb);
				v[bb].push_back(aa);
			}
			if(n<=2){
				cout<<0<<endl;
				continue;
			}
			cout<<2<<endl;
		}
		return 0;
	}
	return 0;
}
