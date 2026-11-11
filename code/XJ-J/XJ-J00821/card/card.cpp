#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	int line[500005]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t=0;
	int ans[m]={0};
	for(int i=1;i<=m;i++){
		for(int j=i-1;j<n;j++){
			for(int h=0;h<j;h++){
				if (line[h]==a[j]){
					t-=j-h-1;
					break;
				}
			}
			line[t]=a[j];
			t++;
		}
		for(int j=0;j<t;j++){
			if (line[j]==a[i]){
				ans[i]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}