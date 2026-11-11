#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+50;
ll c,t,n,d,a[N],ans,pr[N],su[N],prfr[N],sufr[N],mx[N],cnt[N],vis[N];
priority_queue<pair<ll,ll> >q;
bool check(ll l){
	for(int i=l;i<=n;i++){
		mx[i]=1e15;
		cnt[i]=0;
		vis[i]=0;
	}
	mx[l]=0;
	q.push({0ll,l});
	while(!q.empty()){
		pair<ll,ll>t1=q.top();
		q.pop();
		if(-t1.first<mx[t1.second]){
			mx[t1.second]=-t1.first;
			cnt[t1.second]=1;
			vis[t1.second]=0;
		}
		else if(-t1.first==mx[t1.second]){
			cnt[t1.second]++;
		}
		vis[t1.second]++;
		if(vis[t1.second]>3)
		continue;
		for(int i=t1.second+1;i<=n;i++){
			if(a[i]-a[t1.second]>d)
			break;
			q.push({t1.first-1,i});
		}
	}
	for(int i=l;i<=n;i++){
		if(cnt[i]==2){
		ans++;
//		cout<<l<<" "<<i<<endl;
		}
	}
}
void solve(){
	for(ll i=1;i<=n;i++){
		check(i);
	}
	printf("%lld\n",ans);
	return;
}
void solve2(){
	ll k=(d*3)/(a[2]-a[1])/3*3;
	if(a[2]-a[1]>=d){
		printf("0\n");
	return;
	}
//	cout<<n<<" "<<d<<" "<<a[2]-a[1]<<endl;
	printf("%lld\n",max(0ll,n-k));
}
//bool ch(ll id){
//	if(a[id+1]-a[id]>d||a[id+2]-a[id]<=d)
//	return 0;
//	return 1;
//}
//bool ch2(ll id){
//	if(a[id]-a[id-1]>d||a[id]-a[id-2]<=d)
//	return 0;
//	return 1;
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			pr[i]=prfr[i]=su[i]=sufr[i]=0;
		}
		ans=0;
		if(n<=3){
			printf("0\n");
			continue;
		}
		else if(c<=10||n<=1000){
			solve();
			continue;
		}
		else if(c<=12){
			solve2();
			continue;
		}
		else if(c<=14){
//			for(int i=1;i<=n;i++){
//				if(a[n]-a[i]<=d)
//			}
			if(a[n]-a[1]<=d){
				printf("%lld\n",0ll);
			}
			else
			printf("%lld\n",1ll);
		}
		else{
			printf("%lld\n",n*(n+1)/2/3);
		}
//		int l=1;
//		for(int i=1;i<=n;i++){
//			pr[i]=1;
//			while(a[i]-a[l]>d)
//			l++;
//			if(i!=l){
//			pr[i]+=pr[l];
//			prfr[i]=l;
//			}
////			cout<<pr[i]<<"!";
//		}
//		l=n;
//		for(int i=n;i>0;i--){
//			su[i]=1;
//			while(a[l]-a[i]>d)
//			l--;
//			if(i!=l){
//			su[i]+=su[l];
//			sufr[i]=l;
//			}
//		}
//		for(int i=4;i<=n;i++){
//			if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-3]>d){
//				ll l=pr[i-3],r=su[i];
//				cout<<i-3<<" "<<i<<" "<<l<<" "<<r<<endl;
//				if(a[i-2]-a[prfr[i-3]]<=d)
//				l=1;
//				if(a[sufr[i]]-a[i-1]<=d)
//				r=1;
//				ans+=l*r;
////				cout<<i-3<<" "<<i<<endl;
////				int j=i-3;
////				while(j>1&&ch(j-1)){
////					j--;
////				}
////				int k=i;
////				while(k<n&&ch2(k+1)){
////					k++;
////				}
////				cout<<j<<" "<<i-3<<" "<<i<<" "<<k<<endl;
////				ans+=(i-3-j+1)*(k-i+1);
//			}
//		}
//		printf("%lld\n",ans);
	}
}
