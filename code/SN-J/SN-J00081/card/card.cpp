#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],b1[500001];
bool k[500001];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			b[j]=0;
			k[j]=0;
		}
		for (int j=i;j<n;j++){
			if(!k[a[j]]){
				b[j]=a[j];
				k[a[j]]=true;
			}else{
				int y=0;
				for (int o=0;o<n;o++){
					if (b[j] == a[j]){
						y=o+1;
						break;
					}
			}
				for (int o=y;o<n;o++){
					b[j]=0;
				}
			}
		}
		for (int j=1;j<=m;j++){
			for (int o=0;o<n;o++){
				if (b[o] == m){
					b1[j]++;
					break;
				}
			}
		}
	}
	for (int j=1;j<=m;j++){
		cout<<b[j]<<" ";
	}
	return 0;
}
