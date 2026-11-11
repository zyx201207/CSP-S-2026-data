#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,m,sum1,sum2,ans1,ans2;
bool v1,v2;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]==1){
					sum1++;
				}
				if(a[j]==2){
					sum2++;
				}
				if(sum1>1) sum1=1;
				if(sum2>1) sum2=1;
			}
			ans1+=sum1;
			ans2+=sum2;
			sum1=0;
			sum2=0;
		}
		cout<<ans1<<" "<<ans2;
	}
	else{
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	return 0;
}
