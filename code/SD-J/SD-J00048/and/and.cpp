#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N];int qq[40][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	int mx=0,mxc=0;
	for(int i=1;i<=n;i++){
		int t=a[i];
		int cnt=0;
		while(t>0){
			t/=2;
			cnt++;
		}
		mx=max(mx,a[i]);
		mxc=max(mxc,cnt);
		qq[cnt][i]=a[i];
	}
	int res=INT_MIN;
	for(int i=1;i<=mxc;i++){
		int ss=0;bool f=0;int js=m;
		for(int j=n;j>=1;j--){
			if(qq[i][j]>0&&!f){
				ss=qq[i][j];f=1;js--;
			}
			else{
				ss=ss&qq[i][j];js--;
			}
			if(js==0)break;
		}
		if(js==0)res=max(res,ss);
	}
	cout<<res;
	return 0;
} 
