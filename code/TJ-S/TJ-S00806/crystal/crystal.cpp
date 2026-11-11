#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[500005],b[500005],mid,ans;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=(a[i]-a[i-1])*i+b[i-1];
	}
	for(long long i=0;i<n-1;i++){
		x=i+1;
		y=n-1;
		while(x<y){
			mid=(y-x+1)/2;
			if(b[mid+x]-b[i]>m){
				y-=mid;
			}
			else{
				x+=mid;
			}
		
		}
		ans=max(ans,mid-x-i);
	}
	cout<<ans;
	return 0;
}
