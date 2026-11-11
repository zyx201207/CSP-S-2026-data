#include<bits/stdc++.h>
using namespace std;
long long int a[200010],cnt[200010];
long long int DP[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
		DP[i]=a[i];
		cnt[i]=1;
	}
		for(long long int i=2;i<=n;i++){
			long long int ma=0,pos;
			for(int j=1;j<i;j++){
				if(ma<DP[j]&a[i]){
					ma=DP[j]&a[i];
					pos=j;
				}
			}
			if((DP[pos]&a[i])>=DP[i]&&cnt[pos]+1<=m){
				DP[i]=(DP[pos]&a[i]);
				cnt[i]=cnt[pos]+1;
			}
		}
	long long int ma=0;
	for(long long int i=1;i<=n;i++){
		if(cnt[i]==m) ma=max(ma,DP[i]);
	}
	cout<<ma;
	return 0;
}