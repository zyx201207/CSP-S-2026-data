#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b,c,d[500005],cnt=0,cc,bb,cntt=0;
int check(int x){
	for(int i=0;i<cnt;i++){
		if(a[i]==x){
			cntt=i;
			return false;
		}
	}
	return true;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b=a[0];
	for(int i=0;i<n;i++){
		if(a[i]!=b){
			c=a[i];
		}
	}
	for(int i=0;i<n;i++){
		cnt=0;
		for(int j=i;j<n;j++){
			if(check(a[j])){
				d[j]=a[j];
				cnt++;
			}else{
				for(int k=cntt;k<cnt;k++){
					d[k]=0;
				}
			}
		}
		for(int l=0;l<n;l++){
			if(d[l]==b){
				bb++;
			}
			if(d[l]==c){
				cc++;
			}
		}
	}
	cout<<bb<<" "<<cc;
}
