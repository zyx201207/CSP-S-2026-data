#include<bits/stdc++.h>
using namespace std;
const int d=5e5,dd=3e5;
int n,m,a[d+5],qu[d+5];
int t[dd+5];
bool f[d+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int st=1,en=0;
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			qu[++en]=a[j];
			for(int k=st;k<=en-1;k++){
				if(qu[k]==qu[en]){
					if(k==st){
						st=en;
					}
					else{
						for(int l=k;l<=en-1;l++){
							f[l]=1;
						}
					}
					break;
				}
			}
		}
		for(int j=st;j<=en;j++){
			if(f[j]==0){
				t[qu[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
