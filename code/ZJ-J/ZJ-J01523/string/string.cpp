#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long lx=a[l],rx=a[r];
	while(l<r){
		if(lx==rx){
			if(c[l]==c[r]){
				l++;
				r--;
				lx=a[l];
				rx=a[r];
			}
			else{
				ans+=lx;
				l++;
				r--;
				lx=a[l];
				rx=a[r];
			}
		}
		else if(lx<rx){
			if(c[l]==c[r]){
				l++;
				rx-=lx;
				lx=a[l];
			}
			else{
				l++;
				rx-=lx;
				ans+=lx;
				lx=a[l];
			}
		}
		else{
			if(c[l]==c[r]){
				r--;
				lx-=rx;
				rx=a[r];
			}
			else{
				r--;
				lx-=rx;
				ans+=rx;
				rx=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}