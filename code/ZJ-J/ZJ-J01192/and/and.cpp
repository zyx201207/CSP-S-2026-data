#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans,b[200100],cnt;
int f[200100][50],l[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]>>j&1==1)f[i][j+1]=1,l[j+1]++;
		}
	}
	for(int i=30;i>=0;i--){
		if(l[i+1]>=m){
			for(int j=1;j<=n;j++){
				if(f[j][i+1]==1)b[++cnt]=a[j];
			}
			break;
		}
	}
	sort(b+1,b+cnt+1);
	int ans=pow(2,31)-1;
	for(int i=cnt;i>=cnt-m+1;i--){
		ans&=b[i];
	}
	cout<<ans;
	return 0;
}
