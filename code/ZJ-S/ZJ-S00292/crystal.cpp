#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int n,m;
vector<int> a(maxn);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x;
	}
	int o=0;
	for(int u=1;u<=n;u++){
		for(int v=2;v<=n;v++){
			if(a[v]<a[v-1]){
				o=a[v-1];
				a[v-1]=a[v];
				a[v]=o;
			}
		}
	}
	int l=0,r=n;
	int cnt=0;
	for(int p=1;p<=n;p++){
		if(l==r) break;
		int mid=(l+r)>>1;
		int k=mid;
		int sum,ans=0;
		for(int i=k;i<=n;i++){
			sum=0;
			cnt=0;
			for(int j=i-k+1;j<=i;j++){
				cnt=a[i]-a[i-j];
				sum+=cnt;
			}
			if(ans==0){
				ans=sum;
			}
			else {
				ans=min(ans,sum);
			}
		}
		if(ans<m){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout << l;
	return 0;
}