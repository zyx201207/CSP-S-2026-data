#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[200010],z;
bool jl[200010][35],book[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]%2==0){
				jl[i][30-j]=0;
			}else{
				jl[i][30-j]=1;
			}
			a[i]/=2;
			if(a[i]==0)break;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			z=max(z,a[i]);
		}
		cout<<z;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			z=z&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=30;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			if(book[j])continue;
			if(jl[j][i]==1)ans++;
		}
		if(ans<m)continue;
		for(int j=1;j<=n;j++){
			if(jl[j][i]==0){
				book[j]=1;
			}
		}
		z+=(1<<(30-i));
	}
	cout<<z;
	return 0;
}