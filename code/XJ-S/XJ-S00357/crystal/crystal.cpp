#include<bits/stdc++.h>
using namespace std;
int n;
const int more=1e7;
long long m,a[500005],s[500005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0,af=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]+=a[i];
		if(a[i]!=i) f=1;
		if(a[i]>more) af=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			int ak=i*i-i;
			if(ak/2>m){
				cout<<i-1;
				break;
			}
		}
		return 0;
	}
	if(af==1&&f==1){
		sort(a+1,a+n+1,cmp);
		int l=1;
		for(int i=1;i<=n;i++){
			int e=a[l]*(n-l+1)-s[n-l+1];
			if(e<=m){
				cout<<n-l+1;
				return 0;
			}
		}	
	}
	int sum=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		long long s=0;
		int ans=1;
		long long c=a[i];
		for(int j=i+1;j<=n;j++){
			s+=c-a[j];
			if(s>m) break;
			else{
				ans++;
			}
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
} 
