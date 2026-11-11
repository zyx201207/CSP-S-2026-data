#include<bits/stdc++.h>
using namespace std;
long long pai[500005],table[500005],have[300005];
int main(){
	ifstream ci("card.in");
	ofstream co("card.out");
	int n,m;
	ci>>n>>m;
	for(int i=1;i<=n;i++)ci>>pai[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int flag=-1;
			for(int k=j-1;k>=i;k--){
				if(table[k]==pai[j]){
					flag=k;
					break;
				}
			}
			if(flag!=-1){
				for(int k=flag;k<=j;k++)table[k]=0;
			}
			table[j]=pai[j];
		}
		for(int j=i;j<=n;j++){
			have[table[j]]++;
		}
		for(int j=i;j<=n;j++){
			//co<<table[j]<<' ';
			table[j]=0;
		}
	}
	for(int i=1;i<=m;i++)co<<have[i]<<' ';
	return 0;
}
