#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,x[2000010],start[2000010],start_num,wei[2000010],wei_num;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		start_num=1;
		start[1]=1;
		ans=0;
		wei_num=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]>d){
				start_num++;
				start[start_num]=i;
			}
		}
		start_num++;
		start[start_num]=n+1;
		/*for(int i=1;i<=start_num;i++){
			cout<<start[i]<<" "; 
		}
		cout<<endl;*/
		for(int i=1;i<=n-3;i++){
			if(x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i]>d){
				wei_num++;
				wei[wei_num]=i;
			}
		}
		wei_num++;
		wei[wei_num]=n-2;
		/*for(int i=1;i<=wei_num;i++){
			cout<<wei[i]<<" "; 
		}
		cout<<endl;*/
		for(int i=1,j=1;i<wei_num;i++){
			while(start[j+1]<=wei[i]){
				j++;
			}
			ans=ans+(wei[i]-max(wei[i-1],start[j]-1))*(min(wei[i+1]+2,start[j+1]-1)-max(wei[i]+2,start[j]-1));
			//cout<<wei[i]-max(wei[i-1],start[j]-1)<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

