#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			a[i-1]=a[i]-a[i-1];
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				int x=d,cnt=0;
				for(int k=i;k<=j;){
					if(x-a[i]>=0){
						x-=a[i];
						k++;
					}
					else{
						k++;
						x=d;
						cnt++;
					}
				}
				if(cnt%2==j-i+1%2) ans++;
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
