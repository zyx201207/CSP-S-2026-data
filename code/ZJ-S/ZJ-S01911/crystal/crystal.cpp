#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010];
long long mx_zwt;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		long long ans=0;
		long long cnt=0;
		int now_num=i;
		while(ans<=m && now_num>=1){
			long long tx=a[i]-a[now_num];
			ans+=tx;
			if(ans>m){
				break;
			}
			cnt++;
			now_num--;
		}
		mx_zwt=max(mx_zwt,cnt);
	}
	
	cout<<mx_zwt;
	return 0;
}

