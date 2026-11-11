#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+5;
const int inf=LONG_LONG_MAX;
int a[N],ans=0,minn=inf,maxx=-(inf-1);
int n,m;
int check(int k){
	int p=0,mm=m,now=0;
	for(int i=1;i<=n;i++){
		if(a[i]>k){
			p=i-1;
			break;
		}
	}
	for(int i=p;i>=1;i--){
		mm-=k-a[i];
		if(mm<0){
			return now;
		}else{
			now++;
		}
	}
	return now;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>3){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				f=0;
			}
		}
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(f){
		int k=0,t=a[2]-a[1];
		int b=t;
		for(int i=1;i<=n;i++){
			k+=b;
			b+=t;
			//cout<<k<<endl;
			if(k>m){
				cout<<ans+1<<endl;
				return 0;
			}
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=minn;i<=maxx;i++){
		ans=max(ans,check(i));
	}
	//cout<<check(5)<<endl;
	//return 0;
	//cout<<now<<endl;
	/*while(1){
		int j=now+k;
		int p=check(j);
		if(p<ans){
			now+=(k/2/2>0?k/2/2:1);
			if(k==1){
				ans=max(ans,p);
				break;
			}
			k=1;
		}else{
			k*=2;
		}
		ans=max(ans,p);
		//cout<<now<<" "<<k<<endl;
	}*/
	cout<<ans<<endl;
	return 0;
} 
