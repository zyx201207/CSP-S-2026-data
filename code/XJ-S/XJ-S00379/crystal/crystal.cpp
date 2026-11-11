#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
bool cmp(int x,int y){
	return x<y; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		mx=max(a[i],mx);
	}
	int ansx=INT_MIN;
	sort(b+1,b+1+1,cmp);
	for(int k=1;k<=mx;k++){
		cout<<k;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]==k){
				ans++;
			}else if(b[i]<k){
				if(k-b[i]<=m){
					m=m-(k-b[i]);
					ans++;
				}
			}	
		}
		ansx=max(ansx,ans);
	}
	cout<<ansx;
	return 0;
}
