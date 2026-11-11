#include<bits/stdc++.h>
using namespace std;
long long ans,sum[200005];
int n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long ri=1,li=sum[n],mid,midd=-1;
	while(ri<=li){
		mid=ri+li>>1;
		if(mid<(sum[n]+1)/2) ri=mid+1,midd=max(midd,mid);
		else if(mid>(sum[n]+1)/2) li=mid-1; 
		else{
			midd=mid;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>=midd){
			midd=i;
			break;
		}
	}
	int r=1,j=n;
	while(j>=midd+1){
		if(c[r]==c[j]){
			if(a[j]>a[r]){
				a[j]-=a[r];
				r++;
			}else if(a[j]<a[r]){
				a[r]-=a[j];
				j++;
			}else r++,j--;
		}else{
			if(a[j]>a[r]){
				a[j]-=a[r];
				r++;
				ans+=a[r];
			}else if(a[j]<a[r]){
				a[r]-=a[j];
				j--;
				ans+=a[j];
			}else{
				ans+=a[j];
				r++,j--;
			} 
		}
	}
	cout<<ans;
	return 0;
} 
