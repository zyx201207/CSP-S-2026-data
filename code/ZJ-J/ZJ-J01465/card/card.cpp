#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int b[500005];
int ans[300005];
int ta[30000];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(ta,0,sizeof(ta));
		int now=0;
		
		for(int j=i;j<=n;j++){
			//cout<<a[j]<<endl;
			if(b[a[j]]==1){
				int index=-1;
				//cout<<now<<endl;
				for(int k=now;;k--){
					if(ta[k]==a[j]){
						index=k;
						break;
					}
				}
				//cout<<index<<endl;
				for(int k=index;k<=now;k++){
					b[ta[k]]=0;
					ta[k]=-1;
				}
				now=now-index;
				ta[now]=a[j];
				b[a[j]]=1;
			}else{
				b[a[j]]++;
				now++;
				ta[now]=a[j];
				
			}
			
			
		
			
		}
		
		
		for(int k=1;k<=now;k++){
			if(ta[k]<0){
				continue;
			}
			ans[ta[k]]++;
		}
	}
	
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
