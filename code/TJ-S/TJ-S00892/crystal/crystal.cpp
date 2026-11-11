#include<bits/stdc++.h>//fkw
using namespace std;
long long cha[500005],a[500005];
long long n,m,ans1=0,ans2=0,ans3=0,ans=0;
long long maxx=-1e18,minn=1e18;
bool check1(int x){
	memset(cha,0,sizeof(0));
	for(int i=1;i<=n;i++){
		cha[i]=x-a[i];
	}
	sort(cha+1,cha+n+1);
	bool f=1;
	long long cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cha[i]>=0&&sum+cha[i]<=m){
			sum+=cha[i];
			cnt++;
			f=0;
		}
	}
	if((maxx+minn)/2==x){
		return 0;
	}
	if(f||ans1>cnt) return 0;
	else{
		ans1=max(cnt,ans1);
		return 1;		
	}
}
bool check2(int x){
	memset(cha,0,sizeof(0));
	for(int i=1;i<=n;i++){
		cha[i]=x-a[i];
	}
	sort(cha+1,cha+n+1);
	bool f=1;
	long long cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cha[i]>=0&&sum+cha[i]<=m){
			sum+=cha[i];
			cnt++;
			f=0;
		}
	}
	if((maxx+minn)/2==x){
		return 1;
	}
	if(f||ans2>cnt) return 0;
	else{
		ans2=max(cnt,ans2);
		return 1;		
	}
}
bool check3(int x){
	memset(cha,0,sizeof(0));
	for(int i=1;i<=n;i++){
		cha[i]=x-a[i];
	}
	sort(cha+1,cha+n+1);
	bool f=1;
	long long cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cha[i]>=0&&sum+cha[i]<=m){
			sum+=cha[i];
			cnt++;
			f=0;
		}
	}
	if(f||ans3>cnt) return 0;
	else{
		ans3=max(cnt,ans3);
		return 1;		
	}
}
void solve(){
	for(int x=minn;x<=maxx;x++){
		memset(cha,0,sizeof(0));
		for(int i=1;i<=n;i++){
			cha[i]=x-a[i];
		}
		sort(cha+1,cha+n+1);
		bool f=1;
		long long cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cha[i]>=0&&sum+cha[i]<=m){
				sum+=cha[i];
				cnt++;
			}
		}	
		ans=max(cnt,ans);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		minn=min(minn,a[i]);
	}
	if(n*(maxx-minn)<=50000000){
		solve();
		return 0;
	}
	long long l=minn,r=maxx;
	while(l<=r){
		long long mid=(l+r)/2;
		//cout<<mid<<endl;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check1(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	l=minn,r=maxx;
	while(l<=r){
		long long mid=(l+r)/2;
		//cout<<mid<<endl;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check2(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	l=minn,r=maxx;
	while(l<=r){
		long long mid=(l+r)/2;
		//cout<<mid<<endl;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(check3(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<max({ans1,ans2,ans3});
	return 0;
} 
