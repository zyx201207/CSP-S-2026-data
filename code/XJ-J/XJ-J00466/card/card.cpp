#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,r;
long long vis[500005],l;
long long flag,b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			vis[j]=0;
		}
		l=i;
		while(l<=n){
			flag=0;
			for(r=l+1;r<=n;r++){
				if(a[r]==a[l]){
					flag=1;
					break;
				}
			}
			if(flag==1){
				for(long long j=l;j<=r-1;j++){
					vis[j]=1;
				}
				l=r;
			}else l++;
		}
		for(long long j=i;j<=n;j++){
			if(vis[j]==0){
				b[a[j]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		if(b[i]!=0) cout<<b[i]<<" ";
	}
	return 0;
} 
//sha yin jian card4.ans a
//quan shi luan ma mei yi ge zheng chang shu zi
//10:35 pian le 24fen ba
//qiu shang dian fen
//guan zhu luogu:Dong_xk(x he k da xiao xie wang le)
