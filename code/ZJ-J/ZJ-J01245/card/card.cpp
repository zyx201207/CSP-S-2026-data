#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],las[500010],ton[300010],st[300010];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int idx=0;
		for(int j=1;j<=n;j++)st[j]=0;
		for(int j=1;j<=m;j++)las[j]=0;
		for(int j=i;j<=n;j++){
			st[++idx]=a[j];
			if(las[a[j]]){
				for(int k=idx;k>=las[a[j]];k--){
					las[st[k]]=0;
					st[k]=0;
				}
			st[idx]=a[j];
			las[a[j]]=idx;	
			}else{
				las[a[j]]=idx;
			}
		}
		for(int j=1;j<=n;j++){
			ton[st[j]]++;
		}
		cout << endl;
	}
	for(int i=1;i<=m;i++){
		cout << ton[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}