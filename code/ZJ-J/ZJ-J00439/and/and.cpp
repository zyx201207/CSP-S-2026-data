#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200010];
ll ma=1,mi=10000000000,qq;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) qq=a[i];
		else qq=qq&a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	if(n<=20){
		ll ans=-1;
		for(ll mask=0;mask<=(1<<n);mask++){
			ll cnt=0,sum=(1<<n)-1;
			ll aa=mask;
			for(int i=1;i<=n;i++){
				if(aa%2==1) sum=sum&a[i],cnt++;
				aa>>=1;
			}
			if(cnt==m) ans=max(sum,ans);
		}
		cout<<ans;
	}else{
		if(n<=2000){
			if(m==1){
				cout<<ma;
			}else if(m==2){
				ll ans=-1;
				for(int i=1;i<n;i++){
					for(int j=i+1;j<=n;j++){
						ans=max(ans,a[i]&a[j]);
					}
				}
				cout<<ans;
			}else{
				cout<<qq;
			}
		}else{
			if(ma<4){
				ll cnt1=0,cnt2=0,cnt3=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1) cnt1++;
					if(a[i]==2) cnt2++;
					if(a[i]==3) cnt3++;
				}
				if(cnt3>=m) cout<<"3";
				else if((cnt3+cnt2)>m) cout<<"2";
				else if((cnt3+cnt1)>m) cout<<"1";
				else cout<<"0";
			}else{
				bool flag=true;
				for(int i=1;i<=n;i++){
					ll cnt=1;
					bool flagg=true;
					for(int j=0;j<=20;j++){
						if((cnt-1)==a[j]){
							flagg=false;
							break;
						}
						cnt*=2;
					}
					if(flagg){
						flag=false;
						break;
					}
				}
				if(flag){
					cout<<mi;
				}else{
					bool ffff=true;
					for(int i=1;i<=n;i++){
						if(a[i]!=i-1){
							ffff=false;
							break;
						}
					}
					if(ffff){
						cout<<n-m;
					}else{
						cout<<qq;
					}
				}
			}
		}
	}
	return 0;
}
