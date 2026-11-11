#include<bits/stdc++.h>
using namespace std;
int n,m,l[500005];
char a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r=1;
	while(n!=0){
		for(int i=r;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]==a[j]){
					for(int y=j;y<i;y++){
						a[y]=0;
					}
				}
			}
		}
		for(int i=0;i<m;i++){
			if(a[i]!=0){
				l[i]++;
			}
		}
		r++;
	}
	for(int i=1;i<=m;i++){
		cout<<l[i];
	}
	return 0;
}
