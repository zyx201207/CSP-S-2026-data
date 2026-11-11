#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int t[500005]={0};
		bool flag[500005]={true};
		for(int j=i;j<=n;j++){
			if(flag[j]){
				t[j]=a[j];
				flag[j]=false;
			}
			else{
				for(int k=a[j];k<=n;k++){
					t[k]=0;
				}
				t[j]=a[j];
			}
		}
		for(int j=1;j<=n;j++){
			if(t[i]!=0){
				d[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<d[i];
	} 
}
