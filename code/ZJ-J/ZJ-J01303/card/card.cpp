#include<bits/stdc++.h>
#define ll long long
const int N=1e6+10;
using namespace std;
ll n,m,a[N],p[N],ans[N];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[a[j]]!=0){
				for(int k=p[a[j]];k<j;k++){
					p[a[k]]=0;
				}
			}
			p[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(p[j]!=0){
				ans[j]++;
			}
			p[j]=0;
		}
	}
	cout<<ans[1];
	for(int i=2;i<=m;i++){
		cout<<" "<<ans[i];
	}
	return 0;
}
