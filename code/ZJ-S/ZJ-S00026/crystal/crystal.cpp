#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0,ans=0,lst=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(a[i]*(i-lst+1)-sum<=m){
			ans=max(ans,i-lst+1);
		}else{
			while(lst<i && a[i]*(i-lst+1)-sum>m){
				sum-=a[lst];
				lst++;
			}
		}
	} 
	cout<<ans;
	return 0;
}
