#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,len=0,a[maxn],l1[maxn],r1[maxn],l2[maxn],r2[maxn],ans=0;
char c1[maxn],c2[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c1[i];
		len+=a[i];
		l1[i]=r1[i-1]+1;
		r1[i]=l1[i]+a[i]-1;
	}
	for(int i=1;i<=n;i++){
		r2[i]=len+1-l1[n-i+1];
		l2[i]=len+1-r1[n-i+1];
		c2[i]=c1[n-i+1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<l1[i]<<" "<<r1[i]<<" "<<c1[i]<<'\n';
//	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<l2[i]<<" "<<r2[i]<<" "<<c2[i]<<'\n';
//	}
	int tmp=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		while(r1[tmp]<=r2[i]&&tmp<=n){
			if(c1[tmp]!=c2[i]){
				if(l1[tmp]>=l2[i]&&r1[tmp]<=r2[i]){
					sum+=(r1[tmp]-l1[tmp]+1);
				}
				else{
					sum+=(r1[tmp]-l2[i]+1);
				}
			}
			tmp++;
		}
		if(c1[tmp]!=c2[i]&&tmp<=n){
			if(l1[tmp]>=l2[i]){
				sum+=(r2[i]-l1[tmp]+1);
			}
			else{
				sum+=(r2[i]-l2[i]+1);
			}
		}
//		cout<<i<<" "<<tmp<<" "<<sum<<'\n';
		ans+=sum;
	}
	cout<<ans/2<<'\n';
	return 0;
}

