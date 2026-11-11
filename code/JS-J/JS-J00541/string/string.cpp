#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
long long ans,sum,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(cnt<sum/2){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				a[r--]==0;
			}
			else if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				a[l++]=0;
			}
			else{
				cnt+=a[l];
				a[l++]=a[r--]=0;
			}
		}
		else{
			if(a[l]>a[r]){
				cnt+=a[r];
				ans+=a[r];
				a[l]-=a[r];
				a[r--]==0;
			}
			else if(a[l]<a[r]){
				cnt+=a[l];
				ans+=a[l];
				a[r]-=a[l];
				a[l++]=0;
			}
			else{
				cnt+=a[l];
				ans+=a[l];
				a[l++]=a[r--]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}