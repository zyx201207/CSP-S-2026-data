#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005];
int c[300005],v[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int f=0;
		b[i]=a[i];
		v[a[i]]++;
		if(v[a[i]]==2){
			v[a[i]]--;
			for(int j=1;j<i;j++){
				if(b[j]!=a[i]&&b[j]!=0&&f==0){
					c[b[j]]++;
				}
				if(b[j]==a[i]||f==1){
					f=1;
					v[b[j]]--;
					b[j]=0;
				}
			}
		}else{
			for(int j=1;j<=i;j++){
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0; 
}
