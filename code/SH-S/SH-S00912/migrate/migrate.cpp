#include<bits/stdc++.h> 
using namespace std;
vector<int>lj[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[100005];
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			//x[i]-=x[i-1];
		}
		if((x[2]-x[1])<=d){
			lj[1][2].push_back(1);
			if(x[3]-x[1]<=d){
				lj[1][3].push_back(2);
			} 
			else if(x[3]-x[2]<=d){
				lj[1][3].push_back(1);
			}
		}
	for(int h=1;h<=n;h++){
		for(int i=h+1;i<=n;i++){
			for(int j=i-1;j>=h;j--){
				if((x[i]-x[j])<=d){
					//cout<<j<<endl;
					for(int k=0;k<lj[h][j].size();k++){
						lj[h][i].push_back(lj[h][j][k]+1);
					}
				}
				else{
					break;
				}
			}
			//cout<<i<<endl;	
		}
	}
	//cout<<n<<" "<<d;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sort(lj[i][j].begin(),lj[i][j].end());
			//cout<<lj[i][j].size()<<endl;
			if(lj[i][j].size()>=2){
				if(lj[i][j].size()==2){
					if((lj[i][j][0]==lj[i][j][1])){
						ans++;
					}
				}
				else 
				if((lj[i][j][0]==lj[i][j][1])&&(lj[i][j][1]!=lj[i][j][2])){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/	
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
