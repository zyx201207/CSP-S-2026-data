#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],desk[2000005],num[2000005],have[200005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(desk,0,sizeof(desk));
		int u=0;
		for(int j=i;j<=n;j++){
			if(have[a[j]]==0){
				have[a[j]]=1;
				desk[++u]=a[j];
			}
			else if(have[a[j]]==1){
				long long p=0;
				for(int k=1;k<=u;k++){
					if(desk[k]==a[j]){
						p=k;
					}
					if(p){
						have[desk[k]]=0;
					}
				}
			}
			
		}
		for(int q=1;q<=u;q++){
			num[desk[q]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
