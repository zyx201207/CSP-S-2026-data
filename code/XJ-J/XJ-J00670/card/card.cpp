#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],version_max[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		cin >> a[i];
	}
	for(int i=0;i<=n;i++){
		int version[100010];
		for(int j=i;j<=n;j++){
			if(version[a[i]]==1){
				for(int k=i;k<=j;k++) version[a[k]]=0;
			}
			else{
				version[a[i]]=1;
			}
		}
		for(int i=0;i<=n;i++){
			if(version[i]==1){
				version_max[i]+=1;
			}
		}	
	}
		for(int i=0;i<=n;i++){
			cout << version_max[i] << ' ';
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}