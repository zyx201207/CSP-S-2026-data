#include<bits/stdc++.h>
using namespace std;
#define int long long
long long maxx=-1e16,minn=1e16,m,ans=-1000,s[500005],pos,f1,f2;
int a[500005];
//bool cmp(node a,node b){
//	return a.a<b.a;
//}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//x[i].pos=i;
		//maxx=max(maxx,a[i]);
		//minn=min(minn,a[i]);
		//if(a[i]!=i) f1=1;
		if(i>=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=1;
		s[i]=s[i-1]+a[i];
	}
	//cout<<x[259243].a<<endl;
	sort(a+1,a+n+1);
	//cout<<x[1].pos<<endl;
	//cout<<x[1].a;
	for(int i=1;i<=n;i++){
		//x[i].pos=i;
		//maxx=max(maxx,a[i]);
		//minn=min(minn,a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(f2==0){
		for(int i=1;i<=n;i++){
			if(a[n]*(n-i+1)-(a[i]+a[n])*(n-i+1)/2<=m){
				ans=max(ans,n-i+1);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m){
			//	cout<<i-j+1<<endl; 
				if(i-j+1>ans){
					pos=i;
					ans=i-j+1;
				}
				break;
				//pos=j-i+1;
			}
		}
	}
	//cout<<s[pos];//.a-s[ans]<<endl<<pos<<endl;
	cout<<ans;//<<pos;
	/*
	sort(a+1,a+n+1);
	int l=minn,r=maxx;
	while(l<r){
		int mid=(l+r+1)/2;
		int q=0,sum=0,pos;
		int x=lower_bound(a+1,a+n+1,mid)-a;
	//	int x=1;
		if(a[x]==mid) pos=x;
		else pos=x-1;
		cout<<pos<<" "<<mid<<endl;
		for(int k=1;k<=pos;k++){
			q+=(mid-a[k]);
			sum++;
			if(q>m){
				sum--;
				break;
			}
		}
		cout<<sum <<endl;
		if(sum>=ans) r=mid;
		else l=mid+1;
		ans=max(ans,sum);
	}
	cout<<ans;
	*/
} 
