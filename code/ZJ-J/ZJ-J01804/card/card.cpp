#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
struct o{
	bool x;
	int y;
}b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]].x==1){
				for(int k=b[a[j]].y;k<=j;k++){
					b[a[k]].x=b[a[k]].y=0;
				}
				b[a[j]].x=1,b[a[j]].y=j;
			}
			else{
				b[a[j]].x=1,b[a[j]].y=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j].x){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<"\n";
	}
	return 0;
}
