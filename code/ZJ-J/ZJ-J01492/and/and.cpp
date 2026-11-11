#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[200010];
bool b[200010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sm,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=29;i>=0;i--){
		sm=0;
		for(int j=1;j<=n;j++)
			if(!b[j])
				if(a[j]&(1<<i)) sm++;
		if(sm>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!b[j])
					if(!(a[j]&(1<<i))) b[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
