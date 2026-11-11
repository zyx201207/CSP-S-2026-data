#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],f[n+1],zs=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int e[20];
	memset(e,0,sizeof(e));
	for(int i=1;i<=n;i++){
		int lsa=a[i];
		for(int j=0;j<20;j++){
			if(lsa%2==1){
				e[j]++;
			}
			lsa/=2;
			if(lsa==0)break;
		}
	}
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=19;i>=0;i--){
		if(e[i]<m)continue;
		//cout<<i<<':'<<endl;
		for(int j=1;j<=n;j++){
			//cout<<f[a[j]]<<' ';
			if(f[a[j]]==1){
				int lsa=a[j],tf=lsa>>i;
				//cout<<lsa<<' '<<tf<<endl;
				if((tf & 1)==0){
					f[a[j]]=0;
					zs--;
				}
			}
			if(zs==m)break;
		}
		//cout<<zs<<endl;
		if(zs==m)break;
	}
	
	int ans=0,pd=0;
	for(int i=n;i>0;i--){
		if(f[a[i]]!=0){
			if(pd==0){
				ans=a[i];
			}else ans=a[i]&ans;
			//cout<<ans<<endl;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

