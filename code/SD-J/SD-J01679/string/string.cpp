#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n,a[maxn],ans=0;char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	cin>>n;int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//f+=a[i];
	}
	//cout<<f<<" ";
	long long r=n,l=1;
	while(l<=n&&l<r){
		while(a[r]>0){
			if(c[l]==c[r]){
				if(a[l]>=a[r]){
					a[l]-=a[r];
					//cout<<ans<<" ";
					r--;
				}
				else{
					a[r]-=a[l];
					//cout<<ans<<" ";
					l++;
				}
				break;
			}
			else{
				if(a[l]>=a[r]){
					a[l]-=a[r];
					ans+=a[r];
				//	cout<<ans<<" ";
					r--;
				}
				else{
					a[r]-=a[l];
					ans+=a[l];
					//cout<<ans<<" ";
					l++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
