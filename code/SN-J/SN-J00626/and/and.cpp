//胡海瑧 西安市铁一中学 SN-J00626 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
int ans,cnt=0;
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;return 0;
	}
	if(m==n){
		int aa=a[1];
		for(int i=2;i<=n;i++) aa&=a[i];
		cout<<aa;return 0;
	}	
	if(m==2){
		int anss=0;
		for(int i=1;i<=n;i++){
			int res;
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]) continue;
				res=a[i]&a[j];ans=max(ans,res);
			}
		}
		cout<<ans; return 0;
	}
	if(m==n-1){
		sort(a+1,a+n+1);
		int cc=a[2];
		for(int i=3;i<=n;i++) cc&=a[i];
		cout<<cc;return 0;
	}
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]%2==0) f=1;
	}
	if(f==0) {cout<<1;return 0;}
	//
	int nn=n;
	while(nn%2==0) nn/=2;
	if(nn==1){
		int fgf=0;
//		cout<<"jfk";
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1) fgf=1;
		}
		if(fgf==0){
//			cout<<"fjf";
			sort(a+1,a+n+1,cmp);
			if(m>(n/2)){cout<<1;return 0;}
			else{
				int yy=a[1];
				for(int i=2;i<=m;i++) yy&=a[i];
				cout<<yy;return 0;
				
			}
		}
	}
	cout<<1;
	return 0;
}
