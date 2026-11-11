#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int shu;
}a[500005];
bool cmp(node x,node y){
	return x.shu<y.shu;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=-1;
	bool pan=true;
	int cha;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		if(i==2){
			cha=a[2].shu-a[1].shu;
		}
		if(a[i].shu-a[i-1].shu!=cha){
			pan=false;
		}
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(pan==1){
		ans=0;
		int cnt=0; 
		while(cnt+cha*(ans+1)<=m&&ans+1<=n){
			ans++;
			cnt+=cha*ans;
		}
		ans++;
		cout<<min(n,ans);
		return 0;
	}
	for(int mb=1;mb<=n;mb++){//Ä¿±ê a[mb]
		int i=mb;
		int cnt=0;
		int an=0;
		while(i>1&&cnt+a[mb].shu-a[i-1].shu<=m){
			i--;
			an++;
			cnt+=a[mb].shu-a[i].shu;
		}
		//cout<<a[mb].shu<<" "<<i<<endl;
		an++;
		while(a[mb].shu==a[mb+1].shu){
			mb++;
			an++;
		}
		ans=max(ans,an);
	}
	cout<<ans<<endl;
	return 0;
} 
