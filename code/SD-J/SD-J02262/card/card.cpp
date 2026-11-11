#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num[300005],ans[300005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	for(long long i=1;i<=n;i++){
		num[a[i-1]]--;
		for(long long j=1;j<=m;j++){
			if(num[j]%2LL==1){
				ans[j]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}//´ð°¸´íÎó
//4
