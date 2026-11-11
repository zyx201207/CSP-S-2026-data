#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1234561];
int cnt[1234567];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(NULL);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=m;j++){
			cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}


