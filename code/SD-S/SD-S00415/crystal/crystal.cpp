#include<bits/stdc++.h>
#define int long long
using namespace std; 
priority_queue<int,vector<int>,greater<int> >q; 
const int N=5e4;
int n,m,a[500005],x,z,pre[500005],c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
	//	cin>>c[i];
		pre[i]=pre[i-1]+c[i];
		//cout<<c[i]*(i-1)-pre[i-1]+pre[1-1]<<endl;
	}
	z=0;
	for(int i=2;i<=n;i++){
		int l=i,r=n,mid;
		while(l<=r){
		//	cout<<mid<<endl;
			 mid=(l+r)/2;
			if(c[mid]*(mid-i)-pre[mid-1]+pre[i-1]>=m){
				r=mid-1;
			}
			else{
				l=mid+1; 
			}
		}
		z=max(z,mid-i+1);
	}
	cout<<z;
	return 0;
}//rp++
