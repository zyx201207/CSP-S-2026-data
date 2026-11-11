#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],js[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[300001]={0};
		for(int j=i;j<=n;j++){
			t[a[j]]++;
		}
		for(int j=n;j>=i;j--){
			if(t[a[j]]>=2||j==i){
				for(int k=j;k<=n;k++){
					js[a[k]]++;
				}
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
