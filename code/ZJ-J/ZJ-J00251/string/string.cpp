#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],sum;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int l=1,r=sum,lcnt=1,rcnt=n,ans=0;;
	while(l<=r){
		if(b[lcnt]==b[rcnt]){
			if(a[lcnt]>a[rcnt]){
				l+=a[rcnt];
				r-=a[rcnt];
				a[lcnt]-=a[rcnt];
				rcnt--;
			}
			else if(a[lcnt]<a[rcnt]){
				l+=a[lcnt];
				r-=a[lcnt];
				a[rcnt]-=a[lcnt];
				lcnt++;
			}else{
				l+=a[lcnt];
				r-=a[rcnt];
				lcnt++;
				rcnt--;
			}
		}else{
			if(a[lcnt]>a[rcnt]){
				ans+=a[rcnt];
				l+=a[rcnt];
				r-=a[rcnt];
				a[lcnt]-=a[rcnt];
				rcnt--;
			}
			else if(a[lcnt]<a[rcnt]){
				ans+=a[lcnt];
				l+=a[lcnt];
				r-=a[lcnt];
				a[rcnt]-=a[lcnt];
				lcnt++;
			}else{
				ans+=a[rcnt];
				l+=a[lcnt];
				r-=a[rcnt];
				lcnt++;
				rcnt--;
			}
		}
	}
	cout<<ans;
	return 0;
}

