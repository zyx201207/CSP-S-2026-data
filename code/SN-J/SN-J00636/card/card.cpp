//wanghaoyu xidianzhongxue SN-J00636
#include<bits/stdc++.h>
using namespace std;
int n,m,card[500005],table[500005],sum[500005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>card[i];
	}
	int a=n;
	while(a--){
		for(int i=n-a;i<n-i;i++){
			for(int j=0;j<n;j++)table[j]=0;
			for(int j=0;j<i;j++){
				if(table[j]==card[i]){
					for(int k=0;k<i;k++)table[k]=0;
				}
			}
			table[i]=card[i];
		}
		for(int i=0;i<n;i++){
			cout<<table[i]<<' ';
		}
		for(int i=0;i<n;i++){
			if(table[i]==i+1){
				sum[i]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
