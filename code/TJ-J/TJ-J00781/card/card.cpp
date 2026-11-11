#include<bits/stdc++.h>
using namespace std;
int sd[10000000];
int sk[10000];
int cun[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,max=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>sd[i];
		cun[i]+=m; 
	}
	for(int i=0;i<m;i++){
		for(int j=n-1;j>=i;j--){
			max=0;
			for(int z=0;z<max;z++){
				if(sk[z]==sd[j]){
					for(int o=z;o<max;z++){
						sk[z]=0;
						max--;
					}
				}max++;
			}
			for(int h=0;h<max;h++){
				cun[h]++;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<cun[i];
	}
	return 0;
}
