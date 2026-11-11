#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e5+10;

int n,m;
int a[N];
int ans=0;
//int s=0,cnt=1,b[N];
int s[N],cnt[N],b;
bool f[N];
int sqrt(int x,int l,int r){
	if(l>=r)return r;
	int mid=(l+r)/2;
	if(mid*mid>x){
		return sqrt(x,l,mid);
	}else if(mid*mid<x){
		return sqrt(x,mid,r);
	}
	return mid;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	if(n<=5000){
		a[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];	
		}sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			b=a[i]-a[i-1];
			for(int j=i-1;j>0;j--){
				if(!f[j] && s[j]+b*(i-j)<=m){
					s[j]+=b*(i-j);
					cnt[j]++;
				}else{
					f[j]=1;
					break;
				}
			}
				
		}for(int i=1;i<=n;i++){
			if(ans<cnt[i]){
				ans=cnt[i]+1;
			}
		}
		/*
		for(int i=n;i>0;i--){
			s=0;cnt=1;
			for(int j=i+1;j<=n;j++){
				if(s+b[j]*(j-i)>m)break;
				s+=b[j]*(j-i);
				++cnt;
			}if(ans<cnt)ans=cnt;
		}
		*/
		
		cout<<ans;
		return 0;
	}a[0]=0;
	cin>>a[1];
	bool fg=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b=a[i]-a[i-1];	
		if(b!=1){
			fg=1;
			break;
		}
	}if(!f){
		ans=(int)(a+sqrt(1+8*m,10000,1000000000))/2;
		cout<<ans;
		return 0;
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b=a[i]-a[i-1];
		for(int j=i-1;j>0;j--){
			if(!f[j] && s[j]+b*(i-j)<=m){
				s[j]+=b*(i-j);
				cnt[j]++;
			}else{
				f[j]=1;
				break;
			}
		}
			
	}for(int i=1;i<=n;i++){
		if(ans<cnt[i]){
			ans=cnt[i]+1;
		}
	}
	/*
	for(int i=n;i>0;i--){
		s=0;cnt=1;
		for(int j=i+1;j<=n;j++){
			if(s+b[j]*(j-i)>m)break;
			s+=b[j]*(j-i);
			++cnt;
		}if(ans<cnt)ans=cnt;
	}
	*/
	
	cout<<ans;
	
	
	
	
	
	return 0;
	
}