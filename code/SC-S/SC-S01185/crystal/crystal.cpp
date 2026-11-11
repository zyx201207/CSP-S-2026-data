#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N],cha[N],maxx=-1e18;
bool flag1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<n;i++){
		if((a[i]-a[i-1])!=(a[i+1]-a[i])){
			flag1=true;
			break;
		}
	}
	if(n<=5000&&flag1==true){
		int maxx=-1e18;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++) cha[k]=1e18; 
			for(int j=1;j<=n;j++){
				if(a[i]<a[j]) continue;
				cha[j]=a[i]-a[j];
				
			} 
			sort(cha+1,cha+1+n);
			int x=m,c=0,ans=0;
			while(x>=0){
				c++;
				if(cha[c]<=x){
					x-=cha[c];
					ans++;
				}
				if(cha[c]>x){
					break;
				}
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
	}
	if(flag1==false){
		int ch=a[2]-a[1];
		int cnt=0,ans=0;
		while(m>=0){
			cnt++;
			if(m>=(2*cnt*ch)){
				m-=2*cnt*ch;
				ans+=2;
			}
			if(m>=cnt*ch){
				m-=cnt*ch;
				ans++;
			}
			if(m<cnt*ch) break;
		} 
		cout<<ans;
	}
	return 0;
}
