#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio();
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int t[300010],a[500010];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++){
		int qs=i;
		int xt[300010];
		memset(xt,0,sizeof(xt));
		for(int j=i;j<=n;j++){
			if(xt[a[j]]==1){
				memset(xt,0,sizeof(xt));
				xt[a[j]]=1;
				qs=j;
			}
		}
		for(int k=qs;k<=n;k++){
			t[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}*/
	if(m==1){
		cout<<n;
		return 0;
	}/*else if(m==2){
		queue<int> qe;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(qe.empty()){
					qe.push(a[j);
				}else{
					for(int k=i;k<=qe.size();k++){
						if(qe.front()==a[j]){
							
						}
					}
				}
				
			}
		}
	}*/
	int t1[300010];
	for(int i=1;i<=n;i++){
		memset(t1,0,sizeof(t1));
		for(int j=i;j<=n;j++){
			t1[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(t1[j]==1){
				t[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<t[j]<<" ";
	}
	return 0;
}
