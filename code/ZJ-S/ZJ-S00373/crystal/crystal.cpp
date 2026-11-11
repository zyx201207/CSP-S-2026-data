#include<bits/stdc++.h>
using namespace std;
const int N=5002;
int n;
long long m;
long long a[N]={0};
long long b[N][N];
bool vis[N][N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				if(j==i-1){
					b[j][i]=a[i]-a[i-1];
				}else{
					b[j][i]=b[j][i-1]+(a[i]-a[i-1])*(i-j);
					if(b[j][i]<=m){
						maxn=max(maxn,i-j+1);
					}
				}
			}
		}
		cout<<maxn;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int c=a[2]-a[1];
			int ans=0,num=0;
			while(1){
				if(num>n){
					maxn=max(maxn,n);
				}
				if(ans>m){
					maxn=max(maxn,num);
					break;
				}
				num++;
				ans+=c*num;
			}
		}
		cout<<maxn;
	}
	return 0;
}