#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
#define pb push_back
#define endl '\n'
#define kg ' '
#define CLOSE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void Case1();
void Case2();



const int N=5e5+5;

int n,m;
int a[N],b[N],f[N];
int minn=0x3f3f3f3f3f3f3f3f,maxn=-0x3f3f3f3f3f3f3f3f;

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	CLOSE

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	
	sort(a+1,a+n+1);
	
	if(n<=5000&&maxn-minn<=256){
		Case1();
	}
	else{
		Case2();
	}

	return 0;
}

void Case1(){
	
	int ans=-1106;
	int l=minn,r=maxn;
//	while(l<r){
//		int mid=(l+r)
//	}
	
	for(int i=minn;i<=maxn;i++){
		int num=i;
		int sum=0,cnt=0;
		for(int j=1;j<=n;j++){
			b[j]=num-a[j];
		}
		sort(b+1,b+n+1);
		for(int j=1;j<=n;j++){
			if(b[j]<0) continue;
			sum+=b[j];
			if(sum>m){
				break;
			}
			cnt+=1;
		}
		ans=max(ans,cnt);
	}
	
	cout<<ans<<endl;
	
	return;
}

void Case2(){
	
	int ans=0;
	
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
//		cout<<f[i]<<kg;
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<i;j++){
//			cout<<f[i]-f[i-j]-(a[i]-a[i-j])*(i-j-1)<<kg;
//		}cout<<endl;
//	}
	
	for(int i=1;i<=n;i++){
		int l=0,r=i,mid;
//		cout<<i<<"---------\n";
		while(l<r){
			mid=(l+r)>>1;
			int w=f[i]-f[i-mid]-(a[i]-a[i-mid])*(i-mid-1);
//			cout<<l<<kg<<mid<<kg<<r<<kg<<w<<endl;
			if(w>m) r=mid;
			else l=mid+1;
		}
//		cout<<mid<<endl;
		ans=max(ans,r);
	}
	
	cout<<ans<<endl;
	
	return;
}
