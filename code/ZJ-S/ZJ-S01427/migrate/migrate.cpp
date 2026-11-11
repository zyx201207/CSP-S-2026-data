#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=2e6+6;
int c,_;
ll x[N];
int p[N],q[N],l[N];
int t[N],top;
int n; ll d;

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	
	int id=1;
	for(int i=1;i<=n;i++){
		while(x[i]-x[id]>d) id++;
		l[i]=id;
	}
	ll ans=0;
	if(c==11||c==12){
		for(int i=1;i<=1;i++){
			for(int j=i;j<=n;j++) p[j]=0,q[j]=N;
			while(top) top--;
			
			p[i]=1,q[i]=0;
			t[++top]=i;
			for(int j=i+1;j<=n;j++){
				int k=max(i,l[j]);
				
				int x=1,y=top,res=-1;
				while(x<=y){
					int mid=x+y>>1;
					if(t[mid]>=k) res=mid,y=mid-1;
					else x=mid+1;
				}
				if(res==-1) break;
				q[j]=q[t[res]]+1;
				p[j]+=p[t[res]];
				if(res+1<=top&&q[t[res+1]]==q[t[res]]) p[j]+=p[t[res+1]];
				if(res+2<=top&&q[t[res+2]]==q[t[res]]) p[j]+=p[t[res+2]];
				if(p[j]==2) ans+=n-j+1;
				p[j]=min(p[j],3);
				while(top&&q[j]<q[t[top]]) top--;
				t[++top]=j;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) p[j]=0,q[j]=N;
		while(top) top--;
		
		p[i]=1,q[i]=0;
		t[++top]=i;
		for(int j=i+1;j<=n;j++){
			int k=max(i,l[j]);
			
			int x=1,y=top,res=-1;
			while(x<=y){
				int mid=x+y>>1;
				if(t[mid]>=k) res=mid,y=mid-1;
				else x=mid+1;
			}
			if(res==-1) break;
			q[j]=q[t[res]]+1;
			p[j]+=p[t[res]];
			if(res+1<=top&&q[t[res+1]]==q[t[res]]) p[j]+=p[t[res+1]];
			if(res+2<=top&&q[t[res+2]]==q[t[res]]) p[j]+=p[t[res+2]];
			if(p[j]==2) ans++;
			p[j]=min(p[j],3);
			while(top&&q[j]<q[t[top]]) top--;
			t[++top]=j;
		}
	}
	cout<<ans<<'\n';
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--) solve();
	return 0;
}