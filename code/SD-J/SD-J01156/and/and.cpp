#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=pow(2,min(1ll*60,n));i++){
		long long j=i,sum,cnt=1,cnt2=0;
		sum=((long long)pow(2,60)-1);
		while(j!=0){
			if(j%2==1){
				sum=sum&a[cnt];
				cnt2++;
			}
			j=j>>1;
			cnt++;
		}
		if(cnt2==m){
			maxx=max(maxx,sum);
		}
		
	}
	cout<<maxx;
	return 0;
} 
