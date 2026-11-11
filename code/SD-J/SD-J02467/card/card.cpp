#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],t[300010];
int st[300010],top=0;
int anst[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]==1){
				while(st[top]!=a[j]){
					t[st[top]]=0;
					top--;
				}
				
			}else{
				st[++top]=a[j];
				t[a[j]]=1;
			}
		}
		for(int j=1;j<=top;j++){
			anst[st[j]]++;
		}
		memset(t,0,sizeof t);
		top=0;
	}
	for(int i=1;i<=m;i++){
		cout<<anst[i]<<" ";
	}
	return 0;
}

