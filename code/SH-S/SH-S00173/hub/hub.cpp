#include<bits/stdc++.h>
#define pb push_back
using namespace std;
long long C,n,d,pos[2000009],dp[2][200009],ans,u,v;
void solve(){
	return ;
}
void solve1(){
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++) cin>>u>>v;
	if(k==n) cout<<0<<'\n';
	if(k==1){
		int lol=(n/2)+1;
		cout<<(lol+1)/2<<'\n';
	}
	else{
		int lol=(n/2)+1;
		lol-=(k-2);
		cout<<max((lol+3)/4,1)<<'\n';
	}

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C;
	int T=1;cin>>T;
	if(C==13||C==14) while(T--) solve1();
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