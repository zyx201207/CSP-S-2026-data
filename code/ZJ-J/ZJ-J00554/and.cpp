#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans=-1;
string b[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]){
			b[i]+='0'+a[i]%2;
			a[i]/=2;
		}
	}
	int x,y;
	for(int l=2;l<=m;l++){
		if(l==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					string aa=b[i],bb=b[j];
					int z=0,er=1;
					for(int ii=0;ii<max(aa.size(),bb.size());ii++){
						if(aa[ii]=='1'&&bb[ii]=='1')z+=er;
						er*=2;
					}
					if(z>ans){
						ans=z;
						x=i,y=j;
					}
				}
			}
		b[x]='0',b[y]='0';
		}else{
			string aa;
			int ll=0;
			while(ans){
				aa[ll]='0'+ans%2;
				ll++;
				ans/=2;
			}
			ans=-1;
			for(int i=1;i<=n;i++){
				string bb=b[i];
				int z=0,er=1;
				for(int ii=0;ii<max(aa.size(),bb.size());ii++){
					if(aa[ii]=='1'&&bb[ii]=='1')z+=er;
					er*=2;
				}
				if(z>ans){
					ans=z;
					y=i;
				}
			}
			b[y]='0';
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

