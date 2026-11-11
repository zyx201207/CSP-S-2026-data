#include<bits/stdc++.h>
using namespace std;
int n,m,pai[500005],zhuo[300005],cnt,ans[300005];
void moni(){
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			int fang=pai[j];
			for(int k=1;k<=cnt;k++){
				if(zhuo[k]==fang){
					cnt=k-1;
					break;
				}
			}
			zhuo[++cnt]=fang;
		}
		for(int j=1;j<=cnt;j++){
			ans[zhuo[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
	}
	moni();
	return 0;
}//ÄÃ¸ö12·Ö°É 
