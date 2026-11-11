#include<bits/stdc++.h>
using namespace std;
int aa[200010];
int bb[200010];
int ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	
	for(int k=1;k<=n;k++){
		int arr=1,flag;
		for(int i=k;i<=n;i++){
			arr++;
			for(int j=1;j<=arr;j++){
				if(bb[j]==aa[i]){
					arr=j;
					break;
				}
			}
			bb[arr]=aa[i];
		}
		for(int i=1;i<=arr;i++){
			ans[bb[i]]++;
		}
    }
    for(int i=1;i<=m;i++){
    	cout<<ans[i]<<" ";
	}
	return 0;
} 