#include<bits/stdc++.h>
using namespace std;

int n,m,a[500001],ansji[300001];
int zhan[501],zhantop;//1-6
int ji[201];//1-6

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		zhantop=0;
		for(int j=1;j<=m;j++)
			ji[j]=0;
		for(int j=i-1+1;j<=n;j++){
			if(ji[a[j]]==0){
				ji[a[j]]=1;
				zhan[++zhantop]=a[j];
			}else{
				while(true){
					if(zhan[zhantop]==a[j]){
						ji[zhan[zhantop]]--;
						zhantop--;
						break;
					}else{
						ji[zhan[zhantop]]--;
						zhantop--;
					}
				}
				zhan[++zhantop]=a[j];
				ji[a[j]]++;
			}
		}
		for(int j=1;j<=zhantop;j++)
			ansji[zhan[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ansji[i]<<" ";
	return 0;	
}