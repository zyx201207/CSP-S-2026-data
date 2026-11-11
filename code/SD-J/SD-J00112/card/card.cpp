#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,m;
bool f=0;
ll a[502000],cnt[303000];
char c[202000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=n;k>=j;k--){
		        if(a[k]==a[k-1]){
			        x=k+1;
			        break;
	        	}
	        }
	        for(int k=x;k<=n;k++)cnt[k]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
