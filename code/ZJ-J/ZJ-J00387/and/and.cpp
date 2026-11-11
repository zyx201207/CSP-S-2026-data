#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,MAX=1073741823;
int n,m,a[N],maxn=-1,minn=1e7+5,ans=MAX;
bool flag1=true,flag2=true,flag3=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4) flag1=false;
		if((int)log2(a[i]+1)!=log2(a[i]+1)) flag2=false;
		if(a[i]!=i-1) flag3=false;
		ans&=a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(n<=2000){
		if(m==1){
			cout<<maxn;
			return 0;
		}
		if(m==n){
			cout<<ans;
			return 0;
		}
		if(m==2){
			int mx=-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					mx=max(mx,a[i]&a[j]);
				}
			}
			cout<<mx;
			return 0;
		}
	}
	else if(n<=200000){
		if(flag2){
			int da=MAX;
			sort(a+1,a+n+1);
			for(int i=n;i>=n-m+1;i--){
				da&=a[i];
			}
			cout<<da;
		}
		else if(flag3){
			int da=MAX;
			for(int i=n;i>=n-m+1;i--){
				da&=a[i];
			}
			cout<<da;
		}
		else if(flag1){//
			int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt1++;
				if(a[i]==2) cnt2++;
				if(a[i]==3) cnt3++;
				if(a[i]==4) cnt4++;
			}
			if(m<=cnt4) cout<<4;
			else{
				if(m<=cnt3) cout<<3;
				else{
					if(m<=cnt2) cout<<2;
					else{
						if(m<=cnt1) cout<<1;
						else{
							if(m<=cnt2+cnt3) cout<<2;
							else{
								if(m<=cnt1+cnt3) cout<<1;
								else cout<<0;
							}
						}
					}
				}
			}
		}
		else if(m==n-1){//
			int mx=-1;
			for(int i=1;i<=n;i++){
				int da=MAX;
				for(int j=1;j<=n;j++){
					if(j==i) continue;
					da&=a[j];
				}
				mx=max(mx,da);
			}
			cout<<mx;
		}
	}
	return 0;
}


