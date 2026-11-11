#include<bits/stdc++.h>
using namespace std;

int a[200005];
bool flag[200005];
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=1;
	}
	ans=2147483647;
	for(int bt=30;bt>=0;bt--){
		int cnt=0,cnt2=0;
		for(int i=1;i<=n;i++)if(flag[i])cnt+=(a[i]>>bt)&1;
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(flag[i]){
					if((a[i]>>bt)&1){
						flag[i]=1;
						cnt2++;
					}
					else flag[i]=0;
				}
			}
		}
		if(cnt2==m){
			continue;
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i]){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
