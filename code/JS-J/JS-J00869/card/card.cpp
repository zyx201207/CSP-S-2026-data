#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	long long int arr[n],ans[m];
	for(long long int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(long long int i=0;i<m;i++){
		ans[i]=0;
	}
	for(long long int i=0;i<n;i++){
		long long int arr2[n-i];
		for(long long int j=i,k=0;j<n;j++,k++)arr2[k]=arr[j];
		for(long long int j=0;j<n-i;j++){
			for(long long int k=j;k<n-i;k++){
				if(arr2[k]==arr2[j] && arr2[k]!=0 && arr[j]!=0){
					for(long long int a=j+1;a<=k;a++){
						arr2[a]=0;
					}
				}
			}
		}
		for(long long int j=0;j<n-i;j++){
			if(arr2[j]!=0){
				long long int k;
				for(long long int a=1;a<=m;a++){
					if(arr2[j]==a){
						k=a-1;
					}
				}
			ans[k]++;
			}
		}
	}
	for(long long int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
