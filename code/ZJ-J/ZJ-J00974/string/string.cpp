#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const double eps=1e-6;
int n,a[N],c[N],cnt,L[N],ans,posr;
void solve(){
	cin>>n;c[0]=-1;
	for(int i=1;i<=n;i++){
		char ch;
		int x,cc;
		cin>>x>>ch;
		cc=ch-'a';
		if(cc==c[cnt])a[cnt]+=x;
		else a[++cnt]=x,c[cnt]=cc;
	} 
	n=cnt;
	for(int i=1;i<=n;i++)posr+=a[i];
//	cout<<posr<<'\n';
	int l=1,r=n,posl=1,pr=posr;
	while(posl<=posr){
//		cout<<posl<<' '<<posr<<' '<<ans<<'\n';
		if(l==r){
			if(pr&1){
				int mid=(pr+1)/2;
				ans+=abs(posr+posl-mid-mid);
			}
			else{
				int mid=pr/2;
				ans+=abs(posr+posl-mid-mid-1); 
			}
			break;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			posl+=a[l],posr-=a[r];
			l++,r--;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			posl+=a[l],posr-=a[l]; 
			a[r]-=a[l];
			l++;
		}
		if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			posl+=a[r],posr-=a[r]; 
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

