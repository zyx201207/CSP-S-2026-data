#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m;
long long a[N];
long long ans;
long long cnt[4000005];
long long ma;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<0;
    if(n==m){
		ans=a[1]&a[2];
		for(int i=2;i<=n;i++){
		    ans=(ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n and j!=i;j++){
				cnt[i]=max(a[i]&a[j],cnt[i]);
			}
		}
		for(int i=1;i<=N;i++) if(ma<cnt[i]) ma=cnt[i];
		cout<<ma;
	}
	return 0;
}
