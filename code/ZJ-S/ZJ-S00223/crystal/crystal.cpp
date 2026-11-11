#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+1,M=101;
ll a[N+5],sa[N];
int box[M*2];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	ll m,srcm;
	cin>>n>>m;
	srcm=m;
	bool spj=1;
	ll mx=-9e18,mn=9e18;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]),mn=min(mn,a[i]);
	}
	sort(a+1,a+n+1);
	ll de=a[2]-a[1];
	for(int i = 3;i<=n;i++) if(a[i]-a[i-1]!=de){spj=0;break;}
	if(n==1){cout<<1;return 0;}//for hack spj
	if(spj){
		for(int i = 0;i<n;i++){
			if(m-de*i>=0) ans=max(ans,i+1),m-=de*i;
		}
		cout<<ans;
		return 0;
	}//13-18 30pts
	if(mx<=100&&mn>=-100){//move 101(M)
		for(int i = 1;i<=n;i++) box[a[i]+M]++;
		for(int i = -M;i<=M;i++){
			int res=0;
			for(int j = i;j>=-M;j--){
				if(m>=(i-j)*box[j+M]) res+=box[j+M],m-=(i-j)*box[j+M];
				else{
					res+=m/(i-j);
					break;
				}
			}
			ans=max(ans,res),m=srcm;
		}
		cout<<ans;
		return 0;
	}//10-12 15pts
	for(int i = 1;i<=n;i++){
		int l=i,cnt=0;
		while(l>=0&&a[i]-a[l]<=m){
			m-=a[i]-a[l],cnt++,l--;
		}
		ans=max(ans,cnt),m=srcm;
	}
	cout<<ans;//1-9 45pts
	return 0;
}
