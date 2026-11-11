#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],ans=0;
bool an[N][32];
bool cmp(int a,int b){
	return a>b;
}
bool Check(int x){
	for(int i=1;i<=m;i++)
		if(!an[i][x]) return false;
	return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ioi;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			int Mod=(int)pow(2,j);
			an[i][30-j]=a[i]/Mod;
			a[i]%=Mod;
		}
	}
	for(int i=0;i<=30;i++){
		if(Check(i)){
			for(int j=2;j<=m;j++) b[1]&=b[j];
			ans=b[1];
			break;
		}
	}
	cout<<ans;
	return 0;
}