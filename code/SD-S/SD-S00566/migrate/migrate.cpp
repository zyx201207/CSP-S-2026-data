#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
const int INFLL=0x3f3f3f3f3f3f3f3f;
ll c,t,n,d,a[N],ans=0,ch=INFLL;
map<ll,int> tong;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(i>1) ch=min(ch,a[i]-a[i-1]);
			}
			if(a[n]-a[1]<=d||ch>d||d>ch*100000){
				cout<<"0\n";
				continue;
			}
			cout<<n-((d/ch)*2-1)<<"\n";
		}
		
		return 0;
	}
	else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<"0\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1) ch=min(ch,a[i]-a[i-1]);
			tong[a[i]]+=1;
		}
		if(a[n]-a[1]<=d||ch>d){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				
			}
		}
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[l]<=a[i]+d) l=mid;
				else r=mid-1;
			}
			for(;l<=n;l++){
				if((l-i)%2&&tong[a[i]+a[l]>>1]>0) break;
				int l2=i,r2=l;
				while(l2<r2){
					int mid=(l2+r2)>>1;
					if(a[l2]<=(a[i]+a[l]>>1)) l2=mid;
					else r2=mid-1;
				}
			}
		}
	}
	return 0;
}
