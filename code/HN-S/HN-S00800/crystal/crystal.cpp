#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5e5+5;
long long n,m,a[MAX_N],fi[MAX_N],ans=1;
long long le=0,he=1,en=1; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		fi[i]=a[i]-a[i-1];
	}
	while(he<n&&en<n){
		if((fi[en+1]*(en-he+1))+le<=m){
			en++;
			le+=fi[en]*(en-he);
			ans=max(ans,en-he+1);
		}else{
			if(le==0){
				he++;
				continue;
			}
			le-=(a[en]-a[he]);
			he++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
