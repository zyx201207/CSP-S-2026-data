#include<bits/stdc++.h>
using namespace std;
long long a[50006];
long long cnt[50006];
long long ans[50006];
int tot=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];

	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	ans[i]=ans[i-1]+a[i];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
                int u=i-j;
                int val=u*a[i];
                if(u==n||j==0){
                if(ans[i]-ans[j]+m==val){
                tot=max(tot,u);
                }
                else if(ans[i]-ans[j]+m>val){
                tot=max(tot,u-1);
                }
                }
                else{
                if(ans[i]-ans[j]+m>=val){
                tot=max(tot,u);
                }
                }
        }
    }
    cout<<tot;//from 2  boss,and then rush;*/
    return 0;
}
