//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],minn=1e9,cnt,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n,mid=(l+r)/2;
	while(l<r){
		/*5 8
		j       i
		-3 -1 2 2 7
		i=4,j=1,cnt=
		l=4,r=5,mid=4
		min=5
		*/minn=1e9;
		for(int i=mid;i<=n;i++){
			cnt=0;
			for(int j=1;j<=i;j++){
				cnt+=a[i]-a[j];
			}
			minn=min(minn,cnt);
		}
		if(minn<=m){
			maxx=max(maxx,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
		mid=(l+r)/2;
	}
	cout<<maxx;
	return 0;
}
