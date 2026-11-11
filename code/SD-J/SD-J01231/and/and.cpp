#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],cnt,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i))  b[++cnt]=a[j];
		}
		if(cnt>=m){
			for(int j=1;j<=cnt;j++){
				a[j]=b[j];
			}
			n=cnt;
		}
		cnt=0;
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
