#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,t,k,maxx=-1e18,f,ans,cnt,h,sum=0;
LL a[200005];
vector<bool> b[200005];
LL c[200005];
LL d[200005];
bool cmp(LL a,LL b){
	if(a>b) return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=a[i];
		while(t){
			b[i].push_back(t%2);
			t/=2;
		}
		c[i]=b[i].size();
		k=max(k,LL(b[i].size()));
	}
	for(int i=1;i<=n;i++){
		for(int j=b[i].size();j<k;j++){
			b[i][j]=0;
		}
	}
	for(int i=k-1;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(b[j][i]=='0'&&c[j]==0){
				c[j]=i-k;
			}
		}
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,c[i]);
	}
	h=1;
	while(cnt<n){
		for(int i=1;i<=n;i++){
			if(c[i]==maxx){
				cnt++;
				d[cnt]=a[i];
			}
		}
		sort(d+h,d+cnt,cmp);
		LL j=h+1;
		if(f==0) j=1;
//		cout<<h<<" "<<cnt<<"\n";
		while(j<=cnt&&sum<=m){
			sum++;
			if(f==0){
				f=1;
				ans=d[j];
			}
			else{
				ans=ans&d[j];
			}
			if(sum==m){
				cout<<ans;
				return 0;
			}
//			cout<<ans<<"\n";
			j++;
		}
		h=cnt;
		maxx--;
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
