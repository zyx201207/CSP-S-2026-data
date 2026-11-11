#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,cnt,sum=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cnt=m;
	for(int i=1;i<n;i++){
		if((a[i+1]-a[i])*i<=cnt){
			ans++;
			cnt-=(a[i+1]-a[i])*i;
		//cout<<ans<<endl;
			//cout<<a[i+1]<<" "<<a[i]<<endl;
			//cout<<cnt<<endl;
		}
		else{
			ans=i;
			for(int j=i+2;j<=n;j++){
				if(a[i+1]==a[j]) sum++;
				else break;
			}
			if(sum+cnt/(a[i+1]-a[i])>i){
				ans=sum+cnt/(a[i+1]-a[i]);
			}
			break;
		}
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
7 20
1 4 6 9 14 18 20
20 30
1 4 6 6 6 6 6 6 7 8 10 12 12 12 14 17 17 17 17 17
20 29
1 1 1 1 2 2 2 2 4 4 4 4 5 5 5 5 6 6 6 6 
*/
