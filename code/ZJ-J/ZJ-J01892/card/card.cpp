#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int b[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<=5){
		for(int i=1;i<=n;i++){
			int q=0;
			int p=1;
			for(int j=i;j<=n;j++){
				if(!b[a[j]]){
					q+=a[j]*p;
					p*=10;
					b[a[j]]++;
				}
				else{
					q=a[j];
					for(int g=1;g<=m;g++){
						b[g]=0;
					}
					b[a[i]]=1;
					p=10;
				}
			}
			
			for(int k=1;k<=m;k++){
				ans[k]+=b[k];
				b[k]=0;
			}
		}
		
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=m;i>=1;i--){
			if(b[i]>1){
				for(int j=1;j<i;j++){
					cout<<"0 ";
				}
				for(int k=i;k<=m;k++){
					cout<<n<<" ";
				}
				return 0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}