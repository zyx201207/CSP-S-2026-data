#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
bool p[N][33];
int tot[33];
bool ch[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(ch,1,sizeof ch);
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+1+n,greater<long long>());
	if(m==n){
		long long tmp=a[1];
		for(int i=2;i<=n;i++)tmp&=a[i];
		cout<<tmp;
		return 0;
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j))p[i][j]=1,tot[j]++;
			else p[i][j]=0;
		}
	}
	long long ans=0;
	for(int j=30;j>=0;j--){
		for(int i=1;i<=n;i++){
			if(p[i][j]==1&&ch[i]==0)p[i][j]=0,tot[j]--;
		}
		if(tot[j]<m)continue;
		if(tot[j]==m){
			long long andd;
			bool fir=0;
			for(int i=1;i<=n;i++){
				if(p[i][j]==1){
					if(!fir){
						fir=1;
						andd=a[i];
					}else andd&=a[i];
				}
			}
			cout<<andd;
			return 0;
		}
		//tot[j]>m
		ans+=(1<<j);
		for(int i=1;i<=n;i++){
			if(p[i][j]==0)ch[i]=0;
		}
	}
	cout<<ans;
	return 0;
}