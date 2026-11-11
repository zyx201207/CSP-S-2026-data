#include<bits/stdc++.h>
using namespace std;
int a[200005];
int k[200005],s[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int p=0,v=0;
		for(int g=i;g<=n;g++){
			bool flag=1;
			for(int j=1;j<=p;j++){
				if(k[j]==a[g]){
					p=j;
					flag=0;
					break;
				}
			}
			if(flag==1){
				p++;
				k[p]=a[g];
			}
		}
		for(int	g=1;g<=p;g++){
			s[k[g]]++;
			k[g]=0;
		}
		for(int g=p+1;g<=n;g++){
			k[g]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
} 
