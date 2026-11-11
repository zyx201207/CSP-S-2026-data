#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
bool s[500005];
long long y[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[a[j]]==1){
				for(int k=y[a[j]];k<j;k++){
					s[a[k]]=0;
				}
			}
			s[a[j]]=1;
			y[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(s[a[j]]!=0){
				b[a[j]]++;
				s[a[j]]=0;
				y[a[j]]=0;
			}
			else{
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
