#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int w[500005];
int at[500005][2];
int arr[10000][10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>at[j][0]>>at[j][1];
			arr[m+i][at[j][0]]=arr[at[j][0]][m+i]=at[j][1];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m+n;k++){
				if(arr[i][k]>0&&arr[j][k]>0){
					if(arr[i][j]==0||arr[i][k]+arr[j][k]<arr[i][j]){
						arr[i][j]=arr[j][i]=arr[i][k]+arr[j][k];
					}
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		cout<<arr[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}


