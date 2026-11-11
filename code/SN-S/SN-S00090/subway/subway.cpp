#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ans1=0,ans2=100000000;
	cin>>c>>n>>m>>d>>q;
	
	int bxsj[m];
	for(int i=0;i<m;i++){
		cin>>bxsj[i];
	}
	int zs;
	cin>>zs;
	int vv[zs*2][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<2*zs;j++){
			cin>>vv[j][i];
		}
		cin>>zs;
	}
	for(int i=0;i<q;i++){
		int start1,end1,start,end;
		cin>>start1>>end1;
		for(int i=0;i<zs;i++){
			if(vv[i][0]==start1){
				start=i;
			}else if(vv[i][0]==end1){
				end1=i;
			}
		}
		ans1=vv[start][0];
		for(int j=0;j<n;j++){
			for(int k=0;k<zs;k++){
				for(int q=0;q<zs;q++){
					
					if(vv[q][j+1]==vv[k][j] and vv[q][j+1]!=vv[start][0]){
						k=q;
						j=j+1;
						ans1+=bxsj[k]+vv[k+1][j]+vv[q+1][j+1];
					} if(vv[q][j+1]==vv[start][0]){
						ans1+=bxsj[k]+vv[q+1][j+1];
					} if(vv[q][j+1]==vv[end][0]){
						ans1=min(ans1,ans2);
						break;
					}
				}
				k++;
			}
			
		}
		cout<<ans1<<endl;
	}
	
//	0 2 5 20 2
// 4 1 9 2 5
// 3 1 5 2 7 4 6
// 3 2 3 3 4 5 7
// 1 3
// 1 2

	fclose(stdin);
	fclose(stdout);
} 
