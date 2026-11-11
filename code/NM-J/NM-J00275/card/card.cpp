#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],t[n+5],sum[m+5]={0},i1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int qwe=1;qwe<=n;qwe++){
		for(int i=i1,k=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(a[i]==t[j]){
					t[0]=j;
					for(;j<=k;j++){
						t[j]=0;
					}
					k=t[0];
					break;
				}
			}
			t[k]=a[i];
			k++; 
		}
		for(int i=1;t[i]>0;i++){
			sum[t[i]]+=1;
		}
		i1++;
	}
	
	for(int i=1;i<=m;i++){
		if(i==a[n]) sum[i]=sum[i]-n+2;
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
