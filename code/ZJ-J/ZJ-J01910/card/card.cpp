#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[300005],b[500005],c[500005],d;
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
		for(int j=i;j<=n;j++){
			c[++d]=a[j];
			bool f=0;
			for(int k=1;k<d;k++){
				if(c[k]==c[d]){
					f=1;
				}
			}
			d--;
			if(f==1){
				while(1){
					if(c[d]==a[j]){
						break;
					}if(d==0){
						break;
					}
					c[d]=0;
					d--;
				}
			}
			d++;
		}
		while(d!=0){
			b[c[d]]++;
			c[d]=0;
			d--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
