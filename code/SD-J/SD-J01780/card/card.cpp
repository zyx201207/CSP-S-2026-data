#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[300010],cnt,c[500010];
bool v[500010],q[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[a[i]]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[++cnt]=a[j];
			if(j!=i){
				for(int k=1;k<cnt;k++){
					if(c[cnt]==c[k]&&v[c[k]]==true){
						for(int s=k;s<cnt;s++){
							v[c[s]]=false;
							c[s]=0;
						}
						break;
					}
				}
			}
			v[c[cnt]]=true;
		}
		for(int j=1;j<=cnt;j++){
			if(v[c[j]]){
				t[c[j]]++;
			}
			c[j]=0;
			v[c[j]]=false;
			
		}
		cnt=0;
	}
	for(int i=1;i<=300010;i++){
		if(q[i]){
			cout<<t[i]<<" ";
		}
	}
	return 0;
} 
