#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N],s[N],c[N];
bool p[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(p,true,sizeof(p));
	 	for(int j=i;j<=n;j++){
	 		
			c[a[j]]++;
			if(c[a[j]]>1){
				long long z=j-1;
				while(a[z]!=a[j]){
					if(p[z]==true){
						c[a[z]]--;
						p[z]=false;
					}
					
					z--;
				}
				c[a[z]]--;
			}
		}
		for(int k=1;k<=m;k++){
			s[k]+=c[k];
		}                
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;                     
}              