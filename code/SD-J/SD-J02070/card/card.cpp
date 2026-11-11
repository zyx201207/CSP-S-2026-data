#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],c,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		++c;int mm=0,cnt=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==c){
				for(int k=mm;k>=0;k--){
					mm--;
					if(a[k]==a[j])break;
					b[a[k]]=0;
				}mm++;
			}else b[a[j]]=c,mm++;
		}for(int j=1;j<=m;j++){
			if(b[a[j]]==c)ans[a[j]]++;
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
