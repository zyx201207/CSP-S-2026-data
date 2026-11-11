#include<iostream>
using namespace std;
int n,m,card[500005],table[500005],num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>card[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) table[j]=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<j;k++){
				if(table[k]==card[j]){
					for(int ii=k;ii<j;ii++){
						table[ii]=0;
					}
					break;
				}
			}
			table[j]=card[j];
		}		
		for(int j=1;j<=m;j++){
			for(int k=0;k<n;k++){
				if(j==table[k]){
					num[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
