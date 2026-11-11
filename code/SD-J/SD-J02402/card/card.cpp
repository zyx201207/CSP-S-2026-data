#include<bits/stdc++.h>
const int N=5e5+5;
using namespace std;
int n,m,a[N],b[N]={0};
int main(){
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s[N]={0};
		for(int j=i;j<=n;j++){
			if(s[a[j]]==1){
				for(int k=1;k<=m;k++){
					s[k]=0;
				}
				s[a[j]]=1;
			}
			else{
				s[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(s[j]==1){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
