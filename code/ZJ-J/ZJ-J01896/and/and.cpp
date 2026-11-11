#include <bits/stdc++.h>
using namespace std;
int n,m,sum,pre,a[200005],b[35][200005],tmp,t,mxt,f[2][200005],k[2];
int tot;
bool ans[35];
bool p,ok;
inline void cal(const int &x){
	tmp=a[x];t=0;
	while(tmp){
		++t;mxt=max(mxt,t);
		b[t][x]=(tmp%2);
		tmp=tmp>>1;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		f[0][i]=i;
		cal(i);
	} k[p]=n;
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=mxt;++j) cout<<b[j][i];
		cout<<"\n";
	}*/
	for(int i=mxt;i>=1;--i){
		/*cout<<i<<":";
		for(int j=1;j<=k[p];++j){
			cout<<f[p][j]<<" ";
		}
		cout<<"\n";*/
		tot=0;k[!p]=0;
		for(int j=1;j<=k[p];++j){
			if(b[i][f[p][j]]) ++tot;	
		}
		if(tot>=m){
			//cout<<"------------------------ok\n";
			ans[i]=1;
			p=!p;
			for(int j=1;j<=k[!p];++j){
				if(b[i][f[!p][j]]){
					f[p][++k[p]]=f[!p][j];
				}
			}
		}
		else{
			p=!p;
			k[p]=k[!p];
			for(int j=1;j<=k[p];++j){
				f[p][j]=f[!p][j];
			}
		}
		//cout<<tot<<"\n";
	}
	pre=1;
	for(int i=1;i<=mxt;++i){
		sum+=ans[i]*pre;
		pre=pre<<1;
	}
	cout<<sum;
	return 0;
}