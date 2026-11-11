#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN=2e6+5;
int c,t;
int n;
ll d,x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11 || c==12 ){
			ll xd=x[2]-x[1];
		
			int p=d/xd;
			if(p<=1){
				cout<<0<<endl;
				continue;
			}
			p=p*2;
			int ans=max(0,n-p+1);
			cout<<ans<<endl;
			continue;
		}else{
			int ans=0; 
		int head=1,tail=4;
		for(int i=tail;i<=n;i++){
			while(head<=tail && x[i]-x[head]>=2*d){
				head++;
			}
			while(head<=tail && x[i]-x[head]<=d){
				i++;
			}
			tail=i;
			if(x[i]-x[head]<2*d && x[i]-x[head]>d){
				if(tail-head>=3){
					ll sum=x[tail]-x[head];
					int op=lower_bound(x+head,x+tail,x[head]+sum)-x;
					if(x[op]-x[head]==d){
						if(x[tail]-x[op-1]<=d && x[tail]-x[op-2]>d) {
							ans++;
						}
					}else{
						if(x[tail]-x[op-1]<=d && x[tail]-x[op-2]<=d && x[tail]-x[op-3]>d){
							ans++; 
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		}

		
	}
	return 0;
}

