#include<iostream>
using namespace std;
int a[100000];
bool map[1000][1000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	int n,c,t,d;
	cin>>c>>t;
	int start,end,ans1=0;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		int ans1=0,ans=0;
		for(int p=0;p<n;p++){
			cin>>start;
			for(int i=1;i<start;i++){
				if((start-i)%d==0)continue;
				else{
					if((start-i)/d==1){
						ans1++;
						map[i][start]=1;
					}
				}
			}
			for(int j=n;j>start;j--){
				if((j-start)%d==0)continue;
				else{
					if((j-start)/d==1&&!map[start][j]){
						ans1++;
					}
			}
			}
		}
		cout<<ans1<<endl;
	}
}
