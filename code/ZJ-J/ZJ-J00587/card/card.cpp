#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],d[N],c[M];
bool f[M],x=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1]){
			x=0;
		}
	}
	if(x){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				for(int k=1;k<=m;k++){
					f[k]=0;
				}
				for(int k=1;k<=s;k++){
					d[k]=0;
				}
				s=0;
			}
			f[a[j]]=1;
			d[++s]=a[j];
		}
		for(int j=1;j<=s;j++){
			c[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
