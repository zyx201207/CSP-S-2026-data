#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long LL;
int n,m,a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int s=1;s<=n;s++){
		int l=0;
		for(int i=s;i<=n;i++){
			if(d[a[i]]==0){
				l++;			
				c[l]=a[i];
				d[a[i]]++;
			}
			else{
				while(c[l]!=a[i]||l==0) d[c[l]]--,l--;
			}
		}	
		for(int i=1;i<=l;i++){
			b[c[i]]++;
			d[c[i]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
