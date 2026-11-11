#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=1;
long long mm2,m,a[N],qwq;
bool ffll1,ffll2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>5000){
		ffll2=0;
		qwq=a[2]-a[1];
		for(int i=2;i<=n;++i){
			if(a[i]-a[i-1]!=qwq)ffll2=1;
		}
		if(ffll2==0){
			int k=1,ans2=0;
			while(k<=n&&ans2+qwq*k<=m){
				ans2+=qwq*k;
				k++;
			}
			cout<<k;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=2,k;i<=n;++i){
		k=i-1;mm2=m;
		while(k>=1&&a[i]-a[k]<=mm2){
			mm2-=(a[i]-a[k]);
			k--;
		}
		ans=max(ans,i-k);
		//cout<<"k="<<k<<" ans="<<ans<<endl;
	}
	cout<<ans;
}
/*严肃拿下75pts，我的100去哪里*/ 
