#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,cnt=0;
	int maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int m1=m;
		cnt=0;
		for(int j=i-1;j>=1;j--){
			if(m1-a[i]+a[j]>=0){
				m1-=a[i]-a[j];
				cnt++;
				if(cnt>maxn)maxn=cnt;
			}else{
				break;
			}
			
		}
	}
	cout<<maxn+1;
	return 0;
}
