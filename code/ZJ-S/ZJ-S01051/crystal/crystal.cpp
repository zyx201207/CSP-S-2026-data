#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=1,a[500005],p[500005];
bool flagB=true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	p[1]=a[1];
	for(int i=2;i<=n;i++){
		p[i]=a[i]-a[i-1];
		if(i!=2&&p[i]!=p[i-1]){
			flagB=false;
			break;
		}
	}
	if(flagB){
		int pw=p[2],pre1[500005]={0},pre2[500005]={0};
		if(m<pw){
			cout<<1;
			return 0;
		}
		for(int i=2;i<=n;i++){
			pre1[i]=pre1[i-1]+pw;
			pre2[i]=pre2[i-1]+pre1[i];
			if(pre2[i]>m){
				ans=i-1;
				break;
			}
		}
		cout<<(ans==1?n:ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+ans;j<=n;j++){
			ll w=0;
			for(int x=i;x<=j;x++){
				w+=a[j]-a[x];
			}
			//cout<<w<<" ";
			if(w<=m)ans=j-i+1;
			else break;
		}
	}
	cout<<ans;
	return 0; 
}
