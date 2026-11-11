#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[500005];
struct card{
	int mk=false;
	int xb;
}a[500005];
int cnt[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			a[c[i]].xb=i;
			if(a[c[i]].mk==true){
				for(int j=a[c[i]].xb;j>=1;j--){
					a[c[j]].mk=false;
				}
			}
			a[c[i]].mk=true;
			}
		for(int j=1;j<=n;j++){
			if(a[c[j]].mk==true){
				cnt[c[j]]++;
				a[c[j]].mk=false;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
