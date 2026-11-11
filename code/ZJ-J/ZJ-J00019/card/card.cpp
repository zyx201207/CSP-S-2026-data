#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],s[500001],bj[500001],g;
bool h=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			h=0;
		}
	}
	if(h==1){
		for(int i=1;i<=n;i++){
			s[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<s[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(bj,0,sizeof(bj));
		for(int j=i;j<=n;j++){
			if(j==i){
				bj[a[j]]=1;
				g=2;
			}
			else{
				if(bj[a[j]]!=0){
					g=bj[a[j]];
					for(int k=1;k<=m;k++){
						if(bj[k]>g){
							bj[k]=0;
						}
					}
				}
				bj[a[j]]=g;
				g++;
			}
		}
		for(int i=1;i<=m;i++){
			if(bj[i]!=0){
				s[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
