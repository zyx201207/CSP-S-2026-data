#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PID "and"//检查文件名
#define FIN freopen(PID".in","r",stdin)
#define FOUT freopen(PID".out","w",stdout)
int n,m,a[200005],ma,mx;
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//记得开注释 检查文件名
	FIN;
	FOUT;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(m,a[i]);
	}
	if(m==1){
		cout<<ma;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	return 0;
}


