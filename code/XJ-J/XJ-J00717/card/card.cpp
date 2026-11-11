#include<bits/stdc++.h>
using namespace std;
int flag[510],arr[510];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		for(int j=1;j<i;j++){
			if(arr[i]==arr[j]&&flag[j]!=1){
				flag[j]=1;
				for(int a=j;a<=i;a++){
					arr[a]=-1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(arr[i]!=-1){
			cout<<arr[i];
		}
	}
	return 0;
} 
