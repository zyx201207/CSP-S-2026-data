#include<bits/stdc++.h>
using namespace std;
int num,sum,number[500000],number2[500000],ment[500000],node=0,ans=0,tot[500000][500000];
bool flag=true;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>num>>sum;
	for(int i=1;i<=num;i++){
		cin>>number2[i];
	}
	int lin=num;
	while(num){
		node=0;
		for(int i=1;i<=lin;i++){
			number[i]=number2[i];
		}
		for(int i=lin-num+2;i<=lin;i++){
			for(int j=1;j<=node;j++){
				if(number[i]==ment[j]){
					node=j;
					ment[++node]=number[i];
					flag=false;
				}
			}
			if(flag) ment[++node]=number[i];
		}
		for(int i=1;i<=node;i++){
			tot[lin-num+1][i]=ment[i];
		}
		tot[lin-num+1][node+1]=-1;
	}
	for(int i=1;i<=lin;i++){
		ans=0;
		for(int i=1;i<=lin;i++){
			for(int j=1;tot[i][j]!=-1;j++){
				if(tot[i][j]==i){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<' ';
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
