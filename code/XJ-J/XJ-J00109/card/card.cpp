#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500002],ans[500002],tj[500002];
bool pd(int w){
	for(int i=1;i<=n;i++){
		if(a[i]==w) return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pd(a[i])==false){
				int flag=1e9;
				for(int k=1;k<=j;k++){
					if(k>=flag||ans[k]==a[i]){
						flag=k;
						ans[k]=0;
					}
				}
			}
			ans[j-i+1]=a[i];
			
		}
		for(int j=1;j<=n;j++){
			tj[ans[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tj[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
