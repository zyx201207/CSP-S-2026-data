#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long arr[N],flag[N],ji[N]={-1,-1,-1,-1,-1},jw[N],a,b,ans;
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,l=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		l=max(l,arr[i]);
	}
	sort(arr+1,arr+1+n);
	if(m==1){
		cout<<l;
		return 0;
	}
	if(m==n){
		ans=arr[1];
		for(int i=2;i<=n;i++){
			ans=ans&arr[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		ans=arr[i]&arr[i+1];
		if(ans>ji[2]){
			f[i]=1,f[i+1]=1;
			f[a]=0,f[b]=0;
			a=i,b=i+1;
		}
		
		ji[2]=max(ans,ji[2]);
	}
	for(int j=3;j<=m;j++){
		for(int i=1;i<=n-j+1;i++){
			ans=ji[j-1]&arr[i];
			if(f[i]==0&&ans>ji[j]){
				f[i]=1;
				f[a]=0;
				a=i;
			}
			ji[j]=max(ans,ji[j]);
		}
	}
	cout<<ji[m];
	return 0;
} 
