#include<bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int,int>

const int N=2e6+10;

int vis[N],n,arr[N],c,lmt,only[N],lnly[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c;
	int T;
	cin>>T;
	while(T--){
		cin>>n>>lmt;
		queue<P> q,p;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			int b=upper_bound(arr+1,arr+1+n,arr[i]+lmt)-1-arr;
			if(b==i|| b==i+1)continue;
			int a=b-1;
			int c=upper_bound(arr+1,arr+1+n,arr[a]+lmt)-1-arr;
			if(c<=b)continue;
			int kk=lower_bound(arr+1,arr+1+n,arr[c]-lmt)-arr;
			if(kk<a)continue;
			q.push(P{i,c});
			p.push(P{a,b});
		}
		for(int i=1;i<=n;i++){
			only[i]=1;
			lnly[i]=1;
		}
		for(int i=1;i<=n;i++){
			int to=upper_bound(arr+1,arr+1+n,arr[i]+lmt)-1-arr;
			if(to==i)continue;
			only[to]+=only[i];
		}
		
		for(int i=n;i>=1;i--){
			int to=lower_bound(arr+1,arr+1+n,arr[i]-lmt)-arr;
			if(to==i)continue;
			lnly[to]+=lnly[i];
		}
		int ans=0;
		while(!q.empty()){
			int i=q.front().first,c=q.front().second;
			int a=p.front().first,b=p.front().second;
			int j=only[i],k=lnly[c];
			if(upper_bound(arr+1,arr+1+n,arr[b]+lmt)-1-arr!=upper_bound(arr+1,arr+1+n,arr[c]+lmt)-1-arr && upper_bound(arr+1,arr+1+n,arr[b]+lmt)-1-arr!=c)k=1;
			if(lower_bound(arr+1,arr+1+n,arr[i]-lmt)-arr!=lower_bound(arr+1,arr+1+n,arr[a]-lmt)-arr && lower_bound(arr+1,arr+1+n,arr[a]-lmt)-arr!=i)j=1;
			ans+=j*k;
			q.pop();
			p.pop();
		}
		cout<<ans<<endl;
	}

	
	return 0;
}

