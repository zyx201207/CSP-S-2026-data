#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,m,a[200010],ans;
bool ok[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		ok[i]=true;
	}
	for(int i=29;i>=0;i--){
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(ok[j]&&(a[j]&(1<<i))){
				cnt++;
			}
		}
		if(cnt>=m){ 
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(ok[j]&&(a[j]&(1<<i))){
					
				}
				else if(ok[j]){
					ok[j]=false;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
