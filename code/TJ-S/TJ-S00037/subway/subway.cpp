#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int brr[5005][5005],crr[505][50005],arr[5005];
long long cha(int x,int y){

	for(int z=1;z<=m;z++){
		for(int i=1;i<m;i++){
			for(int j=1;j<=m;j++){
				if(brr[i][z]+brr[z][j]+arr[z]<brr[i][j]){
					brr[i][j]=brr[i][z]+brr[z][j]+arr[z];
					brr[j][i]=brr[i][j];
				}
			} 
		}
	}
	return brr[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				brr[i][j]=0;
			}
			else{
				brr[i][j]=1e9;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		arr[i]=a;
	}
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			int b,c;
			cin>>b>>c;
			crr[i][j]=b;
			for(int z=1;z<=j;z++){
				brr[crr[i][z]][b]=brr[crr[i][z]][crr[i][j-1]]+c;
				brr[b][crr[i][z]]=brr[crr[i][z]][b];
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<brr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<arr[a]+cha(a,b)+arr[b]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
