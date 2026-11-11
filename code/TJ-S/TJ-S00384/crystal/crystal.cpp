#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5+3;
long long m;
long long a[N];
long long ans=1;
//unsigned long long f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//f[i]=f[i-1]+a[i];
	}int l=1,r=n;
	bool flag=0;
	sort(a+1,a+1+n);
	while(l<=r){;
		int mid=(l+r)/2;
		for(int i=1;i+mid-1<=n;i++){
			long long cnt=0;
			//cnt=a[i+mid-1]*(mid-1)-(f[mid+i-2]-f[i-1]);
			for(int j=i;j<i+mid-1;j++){
				cnt+=a[i+mid-1]-a[j];
				//cout<<cnt<<" "<<i<<" ";
			}
			if(cnt<=m){
				if(mid>ans)ans=mid;
				flag=1;
			}
		} 
		if(flag){
			flag=0;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
} 
