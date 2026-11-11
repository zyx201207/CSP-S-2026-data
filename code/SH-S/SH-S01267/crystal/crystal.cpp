#include <bits/stdc++.h>
using namespace std;
const int N=500025;
long long n,m,a[N],cnt,ans,d,cost,maxn;
bool b1=true,b2=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=a[i])b1=false;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])b2=false;
	}
	//A
	if(b1){
		for(int i=1;i<=n-1;i++){
			if(m-i<0){
				cout<<i;
				break;
			}
			m-=i;
		}
	}
	
	//B
	if(b2&&!b1){
		int dd=a[2]-a[1];
		for(int i=1;i<=n-1;i++){
			if(m-i*dd<0){
				cout<<i;
				break;
			}
			m-=i*dd;
		}
	} 
	
	if(!b1&&!b2){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			cnt=0;
			cost=0;
			ans=1;
			for(int j=i-1;j>=1;j--){
				d=a[i]-a[j];
				if(cost+d<=m){
					ans++;
					cost+=d;
				}
				else break;
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn<<endl;
	}
	return 0;
}
