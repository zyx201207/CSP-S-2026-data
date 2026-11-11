#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		x[n+1]=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(x[n]-x[1]<=d){
			cout<<"0\n";
			continue;
		}
		bool isA=0;
		int Acha=x[2]-x[1];
		for(int i=2;i<n;i++){
			if(x[i+1]-x[i]!=Acha){
				isA=0;
				break;
			}
		}
		bool isB=0;
		int B=-1;
		int Bcnt=0;
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				isB=1;
				B=i;
				Bcnt++;
			}
		}
		if(isB){
			if(Bcnt>1){
				cout<<"0\n";
				continue;
			}
			long long Bans=0;
			for(int i=1;i<B;i++){
				if(x[i]+d>=x[n])break;
				int to1=upper_bound(x+min(n,max(i+3,B+1)),x+1+n,x[B+1]+d)-x-1;
				int to2=upper_bound(x+min(n,max(i+3,B+1)),x+1+n,x[B+2]+d)-x-1;
				Bans+=to2-to1;
			}
			cout<<Bans<<'\n';
			return 0;
		}
		if(isA){
			if(d<=Acha||d<2*Acha){
				cout<<"0\n";
				continue;
			}
			int maxj=d/Acha;
			(maxj*=2)--;
			cout<<n-(2*maxj-1)<<'\n';
			continue;
		}
		int cnttt=0;
		for(int i=1;i<=n;i++){
			if(x[i]+d>=x[n])continue;
			int jump=upper_bound(x+min(i+3,n),x+1+n,x[i]+d)-x-1;
			int to=upper_bound(x+min(jump+3,n),x+1+n,x[jump]+d)-x-1;
			if(x[jump-1]+d>=x[to])cnttt++;
		}
		cout<<cnttt<<'\n';
	}
	return 0;
}