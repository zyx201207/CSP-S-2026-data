#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int c[5*N+10],cnt[3*N+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	for(int i=1;i<=n;i++){
		bool flag[n+10]{0};
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(c[k]==c[j]&&!flag[k]){
					for(int p=k;p<j;p++){
						flag[p]=true;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!flag[j]){
				cnt[c[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
