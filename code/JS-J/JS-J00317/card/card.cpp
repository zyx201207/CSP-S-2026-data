#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
int a[500010];
int vis[300010];
int ans[300010];
vector <int>p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    //cout<<n;
    for(int i=1;i<=n;i++){
		//cout<<"\n==================P"<<i<<":=======\n";
		//p.clear();
		memset(vis,-1,sizeof vis);
		//for(int u=1;u<=m;u++)cout<<vis[u];
		//cout<<"\nready";
		int tail=0;
		for(int j=i;j<=n;j++){
			//cout<<"\nNo."<<j-i+1<<"push:"<<a[j];
			if(vis[a[j]]!=-1 && vis[a[j]]<=tail){
				//cout<<"##";
				tail=vis[a[j]];
			}else{
				p.push_back(0);
			}
			p[tail]=a[j];
			vis[a[j]]=tail;
			//cout<<"tail:"<<tail;
			//cout<<"\nnow:";
			//for(int i=0;i<=tail;i++)cout<<p[i]<<" ";
			tail+=1;
		}
		//cout<<"\nrest:";
		for(int k=0;k<max(1,tail);k++){
			//cout<<p[k]<<" ";
			ans[p[k]]++;
		}
	}
	//cout<<"\n======================\nans:\n";
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
