#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		long long x=a[i]*(i-1)-pre[i-1]-m;
		int l=0,r=i,k=0;
		while(l<=r){
			int mid=l+r>>1;
			if( (a[i]*mid-pre[mid])>= x ){
				k=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-k);
	}
	cout<<ans;
	
}
