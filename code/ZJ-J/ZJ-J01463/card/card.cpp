#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum[300005];
int a[500005],f[300005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=i;		
		for(int j=1;j<=m;j++){
			f[j]=0;
			s[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				s[k]=a[j];
				k++;
				f[a[j]]=1;			
			}			
			else{				
				f[a[j]]=1;
				while(s[k]!=a[j]){
					f[s[k]]=0;
					s[k]=0;
					k--;
				}
				k++;
			}
		}	
		for(int j=i;j<k;j++){
			sum[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
}
