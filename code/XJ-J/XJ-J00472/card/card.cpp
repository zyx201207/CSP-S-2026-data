#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],ans[N];
struct node{
	int sum,wz;
}t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(t[a[i]].sum!=0){
				for(int j=t[a[i]].wz;j<=i-1;j++){
					t[a[j]].sum=t[a[j]].wz=0;
				}
			}
			t[a[i]].sum=1;
			t[a[i]].wz=i;
		}
		for(int i=k;i<=n;i++){
			if(t[a[i]].sum!=0){
				ans[a[i]]++;
				t[a[i]].sum=t[a[i]].wz=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
