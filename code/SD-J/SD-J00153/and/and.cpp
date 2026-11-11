#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010][50],x,cnt[110],vis[110];
void f10_2(int x,int st){
	int s[1010],l=0;
	while(x){
		s[++l]=x%2;
		x/=2;
	}for(int i=1,j=30;i<=l;i++,j--){
		a[st][j]=s[i];
	}return;
}
void f2_10(){
	int sum=1073741824,ans=0;
	//cout<<sum<<"!!!\n";
	for(int i=1;i<=30;i++){
		sum/=2;
		ans+=cnt[i]*sum;
		//cout<<cnt[i]<<" "<<ans<<" "<<sum<<"\n";
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		f10_2(x,i);
	}
	for(int i=1;i<=30;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(a[j][i]==1){
					sum++;
				}
			}
		}if(sum>=m){
			cnt[i]=1;
			for(int j=1;j<=n;j++){
				if(a[j][i]==0){
					vis[j]=1;
				}
			}
		}
		//cout<<cnt[i]<<"\n";
	}f2_10();
	return 0;
}
