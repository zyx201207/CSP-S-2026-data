#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],tmp[N],tong[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int y=1;y<=n;y++){
			tmp[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			for(int k=i+1;k<=n;k++){
				if(a[k]==a[j]){
					for(int i=j;i<k;k++){
						tmp[i]=0;
					}
				}
				for(int i=1;i<=n;i++){
					if(tmp[i]==0) continue;
					else{
						tong[tmp[i]]++;
					}
				}
			}
		}
		
		
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
//I will AFO on CSP-2026
//goodbye my OI dream QWQ T-T
//luogu id tuotuoyl(别看) 
//祝我whk加油 12:00 886 OI 别炸 
