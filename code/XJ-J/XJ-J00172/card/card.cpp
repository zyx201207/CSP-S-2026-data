#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],t[100000],fir[100000],ans[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n+1;i++){
		for(int j=1;j<=n+1;j++)t[j]=fir[j]=0;
		for(int j=i-1;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
				fir[a[j]]=j;
			}
			else{
				t[a[j]]=1;
				for(int x=j-1;x>=fir[a[j]];x--){
					t[a[x]]=0;
					if(x!=j)fir[a[x]]=0;
				}
				t[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]==1){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
