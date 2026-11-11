#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[1000005],b[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			b[i]=a[i]&a[i-1];
		}
	}
	int maxx=0,maxxx=0;
	while(m!=0){
		for(int i=2;i<=n;i++){
			maxx=max(maxx,b[i]);
			if(maxx<b[i]){
				maxxx=i;
			}
		}
		b[maxxx]=-1;
		cnt+=maxx;
		m--;
	}
	cout<<cnt;
	
	
	return 0;
}
