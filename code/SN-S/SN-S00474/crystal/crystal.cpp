//杜吕俊泽 SN-S00474 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,mx=-1e9-5,cnt=0,mi=1e9+5;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int r=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(m-abs(a[j])>=0){
				cnt++;
				m-=abs(a[j]);
			}else{
				break;
			}
		}
		mx=max(cnt,mx);
		mi=min(cnt,mi);
		m=r;
	}
	cout<<mx-mi;
	return 0;
}

