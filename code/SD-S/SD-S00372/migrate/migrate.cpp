#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
const ll inf=1e16;

int c,t;
ll n,d,a[N],pre[N],s[N],dis[N];

bool fly(int S,int T){
	if(S==0 || T==0)return 0;
	return abs(a[S]-a[T])<=d;
}

ll fff(int x){
	ll y=x;
	for(int i=x;i<=n;i++){
		s[i]=0;
		dis[i]=inf;
		if(fly(i,i+1))y=i+1;
		else break;
	}
	dis[x]=0;
	y=min(y,n);
	for(int i=x;i<=y;i++){
		for(int j=i-1;j>=x;j--){
			if(fly(j,i))dis[i]=min(dis[i],dis[j]+1);
			else break;
		}
	}
	ll res=0;
	s[x]=1;
	for(int i=x;i<=y;i++){
		for(int j=i-1;j>=x;j--){
			if(!fly(j,i))break;
			if(dis[j]+1==dis[i])s[i]+=s[j];
		}
	}
	for(int i=x;i<=y;i++){
		if(s[i]==2)res++;
	}
	return res;
}

void solveNNN(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=fff(i);
	}
	cout <<ans<<"\n";
	return;		
}

void solveA(){
	ll ans=0;
	if(!fly(a[1],a[2])){
		cout <<"0\n";
		return;
	}
	int p=1,q=1;
	for(int i=1;i<=n;i++){
		while(fly(i,p) && p<=n)p++;
		p--;q=max(q,p);
		while(fly(p,q) && q<=n)q++;
		q--;
		ans+=q-p;
	}
	cout <<ans<<"\n";
	return;	
}

void solveB(){
	ll ans=0;
	int p=1;
	for(int i=1;i<=n;i++){
		while(fly(i,p) && p<=n)p++;
		ans+=n-p+1;
		if(p==n+1)break;
	}
	cout <<ans<<"\n";
	return;
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>t;
	for(;t--;){
		cin >>n>>d;
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		sort(a+1,a+n+1);
		if(c<=6){
			solveNNN();
			continue;
		}
		if(c==13 || c==14){
			solveB();
			continue;
		}
		solveA();
		continue;
	}
	return 0;
} 
