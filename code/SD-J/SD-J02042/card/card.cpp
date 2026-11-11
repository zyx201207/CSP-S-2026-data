#include<iostream> 
using namespace std;
int n,m;
long long ca[1000005];
long long pl[1000005];
long long ans[1000005];
long long st[1000005];
int flag[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ca[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<5005;j++){
			pl[j]=0;
			st[j]=0;
			flag[j]=0;
		}
		long long tail=1;
		for(int j=i;j<=n;j++){
			if(pl[ca[j]]==0){
				st[tail++]=ca[j];
				pl[ca[j]]=tail-1;
			}else{
				for(int k=pl[ca[j]]+1;k<tail;k++){
					pl[ca[k]]=0;
				}
				tail=pl[ca[j]]+1;
			}
		}
		for(int j=1;j<tail;j++){
			if(flag[st[j]]==0){
				ans[st[j]]+=1;
				flag[st[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
