#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,myr,n,r,nxt[N],pre[N],l,t[N],top,tmp;
ll d,x[N],cnt,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>myr;
	if(c<=10||c>=13){
		while(myr--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			r=1;
			for(int i=1;i<=n;i++){
				while(r<n&&x[r+1]-x[i]<=d)r++;
				if(r!=i)nxt[i]=r;
				else nxt[i]=0;
			}
			l=n;
			for(int i=n;i>=1;i--){
				while(l>1&&x[i]-x[l-1]<=d)l--;
				if(l!=i)pre[i]=l;
				else pre[i]=0;
			}
			for(int l=1;l<=n-2;l++){
				for(int r=l+2;r<=n;r++){
					tmp=pre[r],top=cnt=0;
					while(tmp>l){
						t[++top]=tmp;
						tmp=pre[tmp];
					}
					tmp=nxt[l];
					while(tmp<r){
						if(tmp-t[top]>1)break;
						if(tmp-t[top]==1)cnt++;
						if(cnt>1)break;
						top--;
						tmp=nxt[tmp];
					}
					if(cnt==1)ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	if(c==11||c==12){
		while(myr--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			r=1;
			while(r<n&&x[r+1]-x[1]<=d)r++;
			nxt[1]=r;
			if(nxt[1]<=2){
				cout<<"0\n";
				continue;
			}
			cout<<max(0,n-2*(nxt[1]-1)+1)<<'\n';
		}
	}
	return 0;
}
