#include<bits/stdc++.h>
#define long long int
using namespace std;
int n,m;
int a[600009];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ft=1,bk=2,vsp=0,maxx=0;
	bool flag=1;
	for(int i=1;i<=n*2;i++){
		if(flag){
			vsp=vsp+(bk-ft)*(a[bk]-a[bk-1]);
		}
		flag=1;
		if(bk==n){
			if(vsp>m){
				maxx=max(maxx,bk-ft);
			}
			break;
		} 
		if(vsp>m){
			vsp=vsp-(a[bk]-a[ft]);
			maxx=max(maxx,bk-ft);
			ft++;
			flag=0;
		}
		else {
			bk++;
		}
	}
	cout<<maxx;//676767
	return 0;//AKIOI
} 
