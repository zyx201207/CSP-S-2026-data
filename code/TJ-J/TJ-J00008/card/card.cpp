#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int MAXK=3e5+5; 
int n,m;
int a[MAXN];
int sum[MAXK];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int cnt=0;
		int b[MAXN]={0};
		for(int j=i;j<n;j++){
			for(int k=0;k<cnt;k++){
				if(b[k]==a[j]){
					cnt=k;
					break;
				}
			}
			b[cnt++]=a[j];
		}
		for(int j=0;j<cnt;j++){
			sum[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
