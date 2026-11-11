#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[1000005];
int ans[1000005];
int minn=INT_MAX;
void bfs(int s,int e,int cnt){
	if(s==e){
		if(minn>cnt) minn=cnt;
		ans[cnt]++;
		//cout<<cnt<<' '<<endl;
		//cout<<endl;
		return;
	}
	for(int j=1;j<=d;j++){
		if(s+j>e) return;
		//cout<<s<<' ';
		bfs(s+j,e,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				minn=INT_MAX;
				int s=x[i],e=x[j];
				for(int i=1;i<=n;i++){
					ans[i]=0;
				}
				//cout<<i<<j<<endl;
				bfs(s,e,0);
				//cout<<endl;
				if(ans[minn]==2) cnt++;
			}
		}
		cout<<cnt<<endl;
	} 
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
