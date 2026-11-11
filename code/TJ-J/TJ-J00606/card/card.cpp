#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],b[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int u=1;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;++j){
			if(u==1){
				b[u]=a[j];
				u++;
			}
			else {
				int flag=0;
				for(int s=1;s<u;++s){
					if(b[s]==a[j]){
						flag=s;
						break;
					}
				}
				if(flag==0){
					b[u]=a[j];
					u++;
				}
				else{
					for(int s=flag;s<=u;++s){
						b[s]=0;
					}
					u=flag+1;
					b[u]=a[j];
					u++;
				}
			}
		}	
		for(int j=1;j<u;++j){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
			cout<<t[i]<<" ";
	}
	return 0;
}
