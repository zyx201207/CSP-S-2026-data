#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freeopen("card.in","r",stdin);
	freeopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]=a[j]){
				for(int x=a[i+1];x<=a[j];x++){
					a[x]=0;
				}
			}
			sum[i]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<sum[i];
	}
}
