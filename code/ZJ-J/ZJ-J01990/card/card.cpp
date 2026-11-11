#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],times[1000005],process[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		memset(process,0,sizeof(process));
		for(int k=i;k<=n;k++){
			for(int j=1;j<flag;j++){
				if(a[k]==process[j]){
					flag=j;
					break;
				}
			}
			process[flag++]=a[k];
		}
		for(int result=1;result<flag;result++){
			times[process[result]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<times[i]<<" ";
	}
	return 0;
}