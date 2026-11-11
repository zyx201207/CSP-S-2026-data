#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
long long n,a[N],maxn,ans;char c[N];string tj;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxn=max(a[i],maxn);
	}
	if(maxn<=50){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				tj+=c[i];
			}
		}
		long long ll=0,rr=tj.size()-1;
		while(ll<=rr){
			if(tj[ll++]!=tj[rr--]) ans++;
		}
		cout<<ans;
	}
	else{
		long long ll=1,rr=n,ans=0;
		while(ll<rr){
			if(a[ll]==a[rr]){
				if(c[ll]!=c[rr]) ans+=a[ll];
				ll++;rr--;
			}
			else if(a[ll]>a[rr]){
				if(c[ll]!=c[rr]) ans+=a[rr];
				a[ll]-=a[rr];rr--;
			}
			else{
				if(c[ll]!=c[rr]) ans+=a[ll];
				a[rr]-=a[ll];ll++;
			}
		}
		cout<<ans;
	}
	return 0;
}