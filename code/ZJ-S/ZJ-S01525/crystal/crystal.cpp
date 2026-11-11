#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N=5e5+5;
int n,m;
int now;
int a[N],b[N];
int s[N];
int ans=1;
bool cmp(int x,int y){
	if(x>=now&&y>=now){
		return (x-now)<=(y-now);
	}
	if(x>=now&&y<=now){
		return (x-now)<=(now-y);
	}
	if(x<=now&&y>=now){
		return (now-x)<=(y-now);
	}
	if(x<=now&&y<=now){
		return (now-x)<=(now-y);
	}
}
signed main(){
	fast;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		now=a[i];
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		sort(b+1,b+n+1,cmp);
		int mm=m;
		for(int j=1;j<=n;j++){
			if(b[j]>now) continue;
			int cha=abs(b[j]-now);
			if((mm-cha)>=0){
				s[i]+=1;
				mm-=cha;
			}
			else{
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,s[i]);
	}
	cout<<ans;
	return 0;
}