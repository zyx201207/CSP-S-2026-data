#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006],b[500005],pdd,c,ans,jsq,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			pdd=114514;
		}
	}
	if(pdd==0){
		for(int i=1;i<=n;i++){
			ans+=i*c;
			if(ans>=m){
				cout<<i+1;
				return 0;
			}
		}
	}
	else{
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				ans+=a[i]-a[j];
				jsq++;
				if(ans==m){
					for(int k=i+1;k<=n;k++){
						if(a[k]==a[i]) {
							jsq++; 
					}
					}
					maxx=max(maxx,jsq+1);
					break;
				}
				else if(ans>m){
					maxx=max(maxx,jsq);
					break;
				}
			}
			ans=0;
			jsq=0;
		}
	}
	cout<<maxx;
	return 0;
} 
