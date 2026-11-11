#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+10,M=1e5+10;
const int mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

ll n,m;
ll a[N],sum,ans;
ll arr[N];
double minn=INF;
int l,r,k;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)arr[i]=arr[i-1]+a[i];
	for(int i=2;i<=n;i++){
		l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			ll d=a[i]*(i-1-mid+1),t=arr[i-1]-arr[mid-1];
//			printf("%d %d %d %d\n",i,l,mid,d-(arr[i-1]-arr[mid-1]));
			if(d-t<=m)r=mid;
			else l=mid+1;
		}
//		cout<<l<<endl;
		ans=max(ans,(ll)(i-l+1));
	}
	printf("%lld\n",ans);
	return 0;
}

