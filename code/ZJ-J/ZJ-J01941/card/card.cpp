#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[500010],x[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int o=1;
	while(n--){
	for(int i=1;i<=n;i++) x[i]=0;
	int cnt=1;
	for(int i=o;i<=n;i++){
		bool f=0;
		for(int j=1;j<=cnt;j++) if(a[i]==x[j]) f=1;
		if(f==0){
				x[cnt++]=a[i];
			}else{
				for(int j=1;j<=cnt;j++) x[j]=0;
				cnt=2;
				x[1]=a[i];
			}
	}
	o++;
	for(int i=1;i<=cnt;i++) s[x[i]]++;	
}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}