#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+6;
int n,m,a[maxn],d,minn=1e18,maxx=-1e18,ans=0,b[maxn];
map<int,int>tot;
map<int,bool>vis;
bool flag=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	maxx=max(maxx,a[i]);
    	minn=min(minn,a[i]);
	}
    sort(a+1,a+1+n);
    int tmpd;
    for(int i=1;i<=n;i++){
    	if(i==1)d=a[i];
    	else if(i==2){
    		d=a[i]-a[i-1];
    		tmpd=d;
		}else{
			d=a[i]-a[i-1];
			if(d!=tmpd)
			flag=false;
    		tmpd=d;
		}	
	}
	if(flag){
		ans=1;
		int mid=n/2;
		int l=mid-1,r=mid+1;
		while(1){
			if(l<1&&r>n)break;
			if(m>=abs(a[mid]-a[l])&&l>=1){
				ans++;
				l--;
			}
			else if(m<abs(a[mid]-a[l])&&l>=0)break;
			m-=abs(a[mid]-a[l]);
			if(m>=abs(a[mid]-a[r])&&r<=n){
				ans++;
				r++;
			}
			else if(m>abs(a[mid]-a[r])&&r<=n+1)break;
		}
	}else{
		for(int i=minn;i<=maxx;i++){
			int res=0,tmpm=m;
			for(int j=1;j<=n;j++){
		    	b[j]=abs(a[j]-i);
			}
			sort(b+1,b+1+n);
			for(int j=1;j<=n;j++){
				if(tmpm<b[j])break;
				res++;
				tmpm-=b[j];
			}
			ans=max(ans,res);
		}
	}
	cout<<ans;
    return 0;
}