//黄伟豪 西安市铁一中学 SN-J00649 
#include<bits/stdc++.h>
using namespace std;
int n,m,top=0;
int a[500005]={0},s[300005]={0},c[300005]={0},ans[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=n;z++){
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		for(int i=z;i<=n;i++){
			c[a[i]]++;
			if(c[a[i]]>1){
				c[a[i]]=1;
				for(int j=1;j<=top;j++){
					if(s[j]==a[i]){
						top=j-1;
						break;
					}
				}
			}
			s[++top]=a[i];
		}
		for(int i=1;i<=top;i++){
			ans[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<< ' ';
	}
	return 0;
}
