#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
bool f;
int a[N],b[M],c[M],l,r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(!f){
		for(int i=1;i<=n;i++){
			cout<<n<<' ';
		}
	}else if(m==1){
		cout<<n;
	}else if(m==2){
		int t=a[n];
		if(t==1){
			long long c=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2) c++;
			}
			cout<<n<<' '<<c;
		}else{
			long long c=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) c++;
			}
			cout<<c<<' '<<n;
		}
	}else if(n<=5000){
		for(int i=1;i<=n;i++){
			r=0;
			for(int j=i;j<=n;j++){
				int q=-1;
				for(int k=1;k<=r;k++){
					if(b[k]==a[j]){
						q=k;
						break;
					}
				}
				if(q==-1)b[++r]=a[j];
				else{
					r=q;
				}
			}
			for(int j=1;j<=r;j++){
				c[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",c[i]);
		}
	}else{
		for(int i=1;i<=m;i++){
			for(int j=n;j>=1;j--){
				if(a[j]==i){
					c[i]=j;
					break;
				}
			}
			cout<<c[i]<<" ";
		}
		
	}
	return 0;
}

