#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],mx=-1e18,l=1,vis[200005],ans=-1,js=0;
int b[200005][30];
bool cmp(long long a,long long b){
	return a>b;
}
void zh(long long a,int c){
	for(int i=l;i>0;i--){
		if(a==0){
			break;
		}
		b[c][i]=a%2;
		a/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	int z=1;
	for(int i=1;i<=30;i++){
		z*=2;
		if(mx<z){
			l=i;
			break;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		zh(a[i],i);
	}
	for(int i=1;i<=l;i++){
		int h=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1)continue;
			h+=b[j][i];
		}
		if(h>=m){
			for(int j=1;j<=n;j++){
				if(b[j][i]!=1){
					vis[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		js++;
		if(ans==-1){
			ans=a[i];
		}else{
			ans&=a[i];
		}
		if(js>=m){
			break;
		}
	}
	cout<<ans;
} 
