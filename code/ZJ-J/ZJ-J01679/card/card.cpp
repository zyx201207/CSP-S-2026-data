#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int f[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		vector<int> d;
		for(int j=i;j<=n;j++){
			for(int k=0;k<d.size();k++){
				if(d[k]==a[j]){
					vector<int> c;
					for(int s=0;s<k;s++){
						c.push_back(d[s]);
					}
					d.clear();
					for(int s=0;s<k;s++){
						d.push_back(c[s]);
					}
					break;
				}
			}
			d.push_back(a[j]);
		}
		for(int j=0;j<d.size();j++){
			f[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}