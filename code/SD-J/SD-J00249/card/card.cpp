#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int const N=5e5+10;
int n,m,a[N],moni[N],ton[N],zb[N],cnt[N]; 
bool flaga=1,flagm=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int q=0,w=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flaga=0;
		if(i==1) q=a[i];
		if(a[i]!=q) w=a[i];
	} 
	if(flaga==1){
		memset(zb,0,sizeof zb);
		for (int i=1;i<=n;i++) zb[a[i]]=i;
		for (int i=1;i<=m;i++) cout<<zb[i]<<" ";
		return 0;
	}
	else if(m<=2){
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++){
			if(a[i]==q) cnt1++;
			else cnt2++;
		}
		if(cnt1==cnt2){
			if(q==a[1]) {
				if(q<w) cout<<cnt1<<" "<<n;
				else cout<<n<<" "<<cnt1;
			}
			else{
				if(q<w) cout<<n<<" "<<cnt2;
				else cout<<cnt2<<" "<<n;
			}
		}
		else if(q<w){
			if(cnt1<cnt2) cout<<cnt1<<" "<<n;
			else cout<<n<<" "<<cnt2;
		}
		else{
			if(cnt1<cnt2) cout<<n<<" "<<cnt1;
			else cout<<cnt2<<" "<<n;
		}
		return 0;
	}
	else if(n<=5000){
		for (int i=1;i<=n;i++){
			memset(moni,0,sizeof moni);
			memset(ton,0,sizeof ton);
			memset(zb,0,sizeof zb);
			for (int j=i;j<=n;j++){
				if(ton[a[j]]==0){
					moni[j]=a[j];
					ton[a[j]]=1;
					zb[a[j]]=j;
				}
				else{
					for (int k=zb[a[j]];k<j;k++)
						ton[a[k]]=0;
					moni[j]=a[j];
					ton[a[j]]=1;
					zb[a[j]]=j;
				}
			}
			for (int j=1;j<=m;j++){
				if(ton[j]!=0) cnt[j]++;
			}
		}
		for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	else{
		memset(zb,0,sizeof zb);
		for (int i=1;i<=n;i++) zb[a[i]]=i;
		for (int i=1;i<=m;i++) cout<<zb[i]<<" ";
		return 0;
	}
	return 0;
}
