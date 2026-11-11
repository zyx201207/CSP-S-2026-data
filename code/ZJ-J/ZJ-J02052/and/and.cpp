#include<bits/stdc++.h>
#define IO freopen("and.in","r",stdin);freopen("and.out","w",stdout);
using namespace std;
const int MAXN=2e5+10;
const int MAXM=40;
long long int A[MAXN];
int vis[MAXN];
int two[MAXN][MAXM];
bool cmp(long long int a,long long int b){
	return a>b;
}
int main(){
	IO
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		long long int s=A[i];
		int cnt=1;
		while(s>=1){
			two[i][cnt]=s%2;
			vis[cnt]+=s%2;
			s/=2;
			cnt++;
		}
	}
	for(int i=1;i<=MAXM;i++){
		if(vis[i]<m){
			for(int o=1;o<=n;o++){
				if(two[o][i]==1){
					A[o]^=(1<<(i-1));
				}
			}
		}
	}
	sort(A+1,A+n+1,cmp);
	long long int ans=A[1];
	for(int i=2;i<=m;i++)ans=(ans&A[i]);
	cout<<ans;
	return 0;
}
