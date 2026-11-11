#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int num=a[i],cnt=1,mm=m;
		for(int j=1;j<=n;j++){
			if(i==j || a[j]>num) continue;
			else if(mm>=num-a[j]){
				cnt+=1;
				mm-=(num-a[j]);
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
}