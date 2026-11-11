#include<bits/stdc++.h>
using namespace std;
const long long N=70001,M=3005;
bool yx[N][M];
long long a[N];
long long k[N][M]; 
long long n,m; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(yx[j][a[i]]==0){
				yx[j][a[i]]=1;
				k[j][a[i]]=i;
				continue;
			}
			if(yx[j][a[i]]==1){
				for(int g=k[j][a[i]];g<=i;g++){
					yx[j][a[g]]=0;
				}
				
				k[j][a[i]]=i;
				yx[j][a[i]]=1;
				continue;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(yx[j][i]==1) sum++;
		}
		cout<<sum<<" ";
	}
	return 0;
}
 


