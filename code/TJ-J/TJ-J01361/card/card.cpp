#include <bits/stdc++.h>
using namespace std;
int main (){
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	int n,m;
    cin>>n>>m;
	int a[n];
	int b[n];
	int ans[m]={0};
	for (int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			a[j]=b[j];
		}
		for (int j=i;j<n;j++){
			for (int k=j+1;k<n;k++){
				if (a[j]!=-1&&a[k]!=-1&&a[j]==a[k]){
					for (int l=j;l<k;l++){
						a[l]=-1;
					}
				}
			}
		}

		for (int j=0;j<m;j++){
			for (int k=i;k<n;k++){
				if (a[k]==j+1){
					ans[j]++;
				}
			}
		}

	}
	for (int j=0;j<m;j++){
		cout<<ans[j]<<" ";
		}
	
	
	
	
	fclose(stdin);
 	fclose(stdout);
	return 0;
}
