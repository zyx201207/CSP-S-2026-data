#include<bits/stdc++.h>
#define pb push_back
using namespace std;
long long C,n,d,pos[2000009],dp[2][200009],ans;
void solve(){
	/*
	pos[1]=1,pos[2]=2,pos[3]=3,pos[4]=3,pos[5]=4;
	//cout<<upper_bound(pos+1,pos+1+5,3)-pos<<'\n';
	*/
	memset(dp,0,sizeof(dp)); ans=0;
	//cout<<"Qwq\n";
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>pos[i];

	for(int i=1;i<=n;i++) dp[0][i]=1;

	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(pos[i]+d<pos[j]){ cout<<j-1<<' '; break;}
		}
	}
	*/
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		ans+=dp[1][i];
		int Fi=upper_bound(pos+1,pos+1+n,pos[i]-d-1)-pos;
		int Se;
		if(i+1<=n) Se=upper_bound(pos+1,pos+1+n,pos[i+1]-d-1)-pos-1;
		else Se=n;
		//cout<<Fi<<' ';
		//cout<<Fi<<"->"<<Se<<' ';
		long long x=0,x2=0;
		for(int j=Fi;j<=Se;j++) x+=dp[0][j];
		for(int j=Fi;j<=Se;j++) x2+=dp[1][j];

		int Fii;
		if(i-1>=1) Fii=upper_bound(pos+1,pos+1+n,pos[i-1]+d)-pos;
		else Fii=1;
		int See=upper_bound(pos+1,pos+1+n,pos[i]+d)-pos-1;
		//cout<<See<<' ';
		for(int j=Fii;j<=See;j++) dp[0][j]+=x;
		for(int j=Fii;j<=See;j++) dp[1][j]+=x2;
		//cout<<Fii<<"->"<<See<<' ';

		if(i!=1){
			int Fiii;
			if(i>=1) Fiii=upper_bound(pos+1,pos+1+n,pos[i-2]+d)-pos;
			else Fiii=1;
			int Seee=upper_bound(pos+1,pos+1+n,pos[i-1]+d)-pos-1;
			//cout<<Fiii<<"->"<<Seee<<' ';

			for(int j=Fiii;j<=Seee;j++) dp[1][j]+=x;

		}
		//cout<<"x="<<x<<' ';
		/*
		{
			int x=i;
			//cout<<i<<"awa\n";
					//cout<<"qwq";
			if(x-1<1||pos[x-1]+d<pos[x+1]){
						//cout<<"qwq";
						//cout<<pos[x]<<' '<<d<<' '<<pos[x+2]<<'\n';
				if(x+2>n||pos[x]+d<pos[x+2]){
						//cout<<"qwq";
					if(pos[x]+d>=pos[x+1]){
						//cout<<"qwq";
						//cout<<x<<' ';
						//cout<<dp[0][x+1]<<' '<<dp[0][x]<<'\n';
						dp[1][x+1]+=dp[1][x];
						dp[0][x+1]+=dp[0][x];
					}
				}
			}
		}
		*/
		//cout<<'\n';
	}
	//for(int i=1;i<=n;i++){
	//	cout<<dp[0][i]<<' '<<dp[1][i]<<'\n';
	//}
	cout<<ans<<'\n';
	return ;


	/*
	for(int i=1;i<=n;i++){
		long long y=upper_bound(pos+1,pos+1+n,pos[i]+d)-pos-1;
		//cout<<y<<"qwq\n";
		//if(y==n+1) continue;
		if(y==i) continue;
		long long z=upper_bound(pos+1,pos+1+n,pos[y]+d)-pos-1;
		long long z2=upper_bound(pos+1,pos+1+n,pos[y-1]+d)-pos-1;
		z2=min(n,min(z,z2));
		long long k=0;
		if(y-2>=1) k=upper_bound(pos+1,pos+1+n,pos[y-2]+d)-pos-1;
		k=max(k,y);
		cout<<i<<' '<<y<<' '<<k<<' '<<z2<<'\n';
		//for(int j=k+1;j<=z2;j++){
		//	cout<<i<<' '<<j<<'\n';
		//}
		
		for(int j=y+1;j<=k;j++){
			dp[0][j]+=dp[0][i];
			dp[1][j]+=dp[1][i];
		}
		for(int j=k+1;j<=z2;j++){
			dp[1][j]+=dp[0][i];
		}
		ans+=dp[1][i];
		
		//cout<<t<<' ';
	}
	cout<<ans<<'\n';
	*/
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>pos[i];
	long long k=pos[2]-pos[1];
	long long p=d/k;
	//cout<<k<<' '<<d<<'\n';
	if(p<=1||p*2-1>=n){
		cout<<0<<'\n';
		return ;
	}else{
		int l=p*2-1;
		cout<<n-l<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C;
	int T=1;cin>>T;
	if(C==11||C==12) while(T--) solve1();
	//else if(C==13||C==14) while(T--) solve2();
	else while(T--) solve();
}
/*
5 5 
1 2 4 8 9
*/
/*
diff subway7.out subway7.ans


when its 

x -> y  ->z
x -> y-1 ->z
cant x -> y-2 ->z
its the 2paths from x to z
now we count the cnt of the only path from x1->x and z->z1
mul them.



5 3
-3 0 2 3 4


10 21
0 7 14 21 28 35 42 49 56 63

how to count the path that only 1 path to arrive?
dp.
we choose the path that arrive in 2 round with only 1 way
1 round< x < 2 round 2 path.
*/