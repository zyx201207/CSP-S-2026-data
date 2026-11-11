#include<bits/stdc++.h>
using namespace std;
int n,m,m_m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]>=a[i-1]){
		m_m++;}
	} 
	if(m_m==n){
	for(int i=1;i<=m;i++){
		cout<<n<<" ";return 0;
	}}
	int l=0;
	for(int i=1;i<=n;i++){
		l=i;
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					j=k-1;
					l=k;
					break;
				}
			}
			
		}
		for(int j=l;j<=n;j++){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;	
} 
