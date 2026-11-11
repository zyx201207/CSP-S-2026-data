#include<bits/stdc++.h>
using namespace std;
int a[5050],c1[5050],c2[5050],ans[5050];
int main(){
	freopen("card.in" ,"r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			c1[i]=a[i];
			for(int c=x;c<i;c++){
				if(c1[i]==c1[c]){
					for(int cc=c+1;cc<=i;cc++){
						c1[cc]=0;
					}
					break;
				}
			}
		}
		for(int c=x;c<=n;c++){
			ans[c1[c]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
