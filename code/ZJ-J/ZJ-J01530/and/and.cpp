#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,ma,p[25];
map<int,int> f[N],d[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=20;i++) p[i]=pow(2,i)-1;
	int f1=1,p1=0,p2;
	cin>>n>>m;
	for(int i=1;i<=20;i++) if(n==p[i]+1) p1=1,p2=i;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(p1){
			if(a[i]!=i-1) p1=0;
		}
		if(f1){
			ma=max(ma,a[i]);
			int f2=0;
			for(int j=1;j<=20;j++){
				if(a[i]==p[j]){
					f2=1;
					break;
				}
			}
			if(!f2) f1=0;
		}
	}
	if(f1==1){
		cout<<a[n-m+1];
	}
	else if(p1==1){
		if(m>n/2) cout<<0;
		else cout<<pow(2,p2-1);
	}
	else{
		for(int i=1;i<=n;i++){
			f[1][i]=a[i];
			for(int j=m;j>=1;j--){
				for(int k=1;k<i;k++){
					f[j][i]=max(f[j-1][k]&a[i],f[j][i]);
				}
			}
		}
		for(int i=1;i<=n;i++) ans=max(f[m][i],ans);
		cout<<ans;
	}
}
