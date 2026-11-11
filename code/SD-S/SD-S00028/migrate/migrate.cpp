#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10; 
int c,T,n,l[N],r[N],tl[N],tr[N];
ll a[N],b[N],d,ans;
void work(ll a[],int l[],int res[]){
	int t[N]={},p=1,pp=1,lp=1,tl[N]={},tr[N]={}; 
	a[0]=-4e18;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]>d)continue;
		while(a[i]-a[p]>d)p++;
		while(a[i+1]-a[pp]>d)pp++;
		if(i>=3)while(a[i-1]-a[lp]>d)lp++;
		if(l[i-1]){
			l[i]=l[i-1];
			while(a[i]-a[l[i]]>d)l[i]++;
		}
		else l[i]=i-1;
		int x=pp-p;
		tl[i]=p,tr[i]=pp;
		if(pp>i)x--,tr[i]--;
		//cout<<"SB"<<i<<" "<<l[i]<<" "<<p<<" "<<pp<<" "<<x<<endl;
		t[i]=t[l[i]]+x;
		if((l[i]<i-1)&&l[l[i]]&&(a[l[i]+1]-a[l[l[i]]]<=d))t[i]=x;
		if(pp>i-1&&p<i)x--;
		if(l[i]<i-1){
			if(l[i]<p||l[i]>=pp||l[i]==i-1)continue;
			res[i]=t[l[i]]+x;
			//cout<<"@$@$#@$"<<i<<" "<<a[l[i]+1]-a[l[l[i]]]<<" "<<x<<endl;
			if(l[l[i]]&&(a[l[i]+1]-a[l[l[i]]]<=d))res[i]=x;
			else{
				int L=tl[l[i]],R=tr[l[i]];
				R=min(R,l[i]-1);
				L=max(L,lp);
				res[i]-=max(0,R-L+1);
				//if(i==5)cerr<<"@$@#$@#$@#"<<l[i]<<" "<<L<<" "<<R<<endl;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)cin>>a[i],l[i]=r[i]=tl[i]=tr[i]=0,b[i]=a[i];
		reverse(b+1,b+1+n);
		for(int i=1;i<=n;i++)b[i]=-b[i];
		work(a,l,tl),work(b,r,tr);
		reverse(r+1,r+1+n),reverse(tr+1,tr+1+n);
		for(int i=1;i<=n;i++)if(r[i])r[i]=n-r[i]+1;
		/*
		for(int i=1;i<=n;i++)cout<<l[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)cout<<tl[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)cout<<r[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)cout<<tr[i]<<" ";cout<<endl;
		*/ 
		for(int i=2;i+1<n;i++)
			ans+=1ll*tr[i]*tl[i+1];//,cout<<"$"<<i<<" "<<tr[i]<<" "<<tl[i+1]<<endl;
		cout<<ans<<"\n";
		//return 0;
	}
	return 0;
}
