#include<bits/stdc++.h>
using namespace std;
long long c=1,n,m,a[500005],cnt=0,sum=0,maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			c=0;
		}
	}
	if(c==0){
		for(int i=2;i<=n;i++){
			cnt=0;
			sum=0;
			for(int j=i-1;j>=1;j--){
				sum+=(a[i]-a[j]);
				if(sum>m){
					break;
				}
				else{
					cnt++;
				}
			}
			maxx=max(cnt,maxx);	
		}
	}
	else{
		for(int i=n-1;i>=1;i--){
			sum+=(a[n]-a[i]);
			if(sum>m){
				break;
			}
			else{
				cnt++;
			}
		}
		maxx=cnt;
	}
	cout<<maxx+1;
	return 0;
}
