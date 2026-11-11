#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s[300005]={0};
		int r=0;
		bool f=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=r;k++){
				if(a[j]==s[k]){
					for(int g=s[k]+1;g<=j;g++){
						s[g]=0;
					}
					f=1;
					r=r-(j-2);
					break;
				}
			}
			if(f==0){
				r++; 
				s[j]=a[j];
			}
			f=0;
		}
		for(int j=1;j<=m+1;j++){
			ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
