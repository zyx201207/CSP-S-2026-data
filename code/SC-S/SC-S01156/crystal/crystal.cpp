#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int s[N];
int k[N];
int cnt=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	int rec=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			rec=a[i+1]-a[i];
		}
		if(a[i+1]-a[i]!=rec&&i!=n)f=0;
	}
	if(a[n]-a[n-1]!=rec)f=0;
	if(f==1){
		int num=1;
		while(m>=0){
			m-=(num*rec);
			num++;
		}
		cout<<num-1;
		return 0;
	}else{
		int ans=0;
		sort(1+a,1+a+n);
		for(int i=2;i<=n;i++){
			int num=i-1;
			int cnt=1;
			while(m>=0&&num>=1){
				m-=(a[i]-a[num]);
				num--;
				cnt++;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					cnt++;
				}
			}
			//cout<<cnt<<endl;
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/