//CH99!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+24;
int n,m,ans,maxn;
struct Node{
	int x;
	string Two;
}a[N];//Bobo!
string to_Two(int x){
	string rn;
	while(x!=0){
		rn+=x%2+'0';
		x/=2;
	}
	while(rn.size()<=33)rn+='0';
	return rn;
}
bool cmp(Node a,Node b){
	return a.x>b.x;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//CintieGivesMeEnerge! 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		maxn=max(maxn,a[i].x);
		a[i].Two=to_Two(a[i].x);
	}
	
	int p=0;
	while(maxn!=0){
		maxn/=2;
		p++;
	}
	
	for(int i=p;i>=0;i--){
		int cnt=0;
		sort(a+1,a+1+n,cmp);
		for(int j=1;j<=n;j++)
			if(a[j].Two[i]=='1')cnt++;
			else break;
		
		int k=(1<<i);
		if(cnt>=m){
			n=cnt;
			ans+=k;
		}
		for(int j=1;j<=n;j++)
			if(a[j].Two[i]=='1')a[j].x-=k;
	}
	cout<<ans;
	return 0;
}
