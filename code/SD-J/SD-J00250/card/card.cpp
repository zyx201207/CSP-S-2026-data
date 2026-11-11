#include<bits/stdc++.h>
using namespace std;
int pai[500005];
int ans[300005];
int dq[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,pow=1;//I love CCF
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<pow;k++){
				if(pai[j]==dq[k]){
					pow=k;
					break;
				}
			}
			dq[pow]=pai[j];
			pow++;
		}
		for(int j=i;j<pow;j++){
			ans[dq[j]]++;
		}
		pow=i;
		for(int j=0;j<=n;j++){
			dq[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]+1<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
