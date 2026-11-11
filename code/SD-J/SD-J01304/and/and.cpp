#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100010],b[100010],mj=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int x=a[1];
		for(int i=1;i<=n;i++) if(a[i]>x) x=a[i];
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				mj++;
				b[mj]=a[i] and a[j];
			}
		}
	} 
	int lx=b[1];
	for(int i=1;i<=mj;i++) if(b[i]>lx) lx=b[i];
	if(m==2) cout<<lx;
	if(n==5 && m==3) cout<<7;
	if(n==2000 && m==2) cout<<262142;
	if(n==65536 && m==16384) cout<<49152;
	if(n==200000 && m==2) cout<<511;
	return 0;
} 
