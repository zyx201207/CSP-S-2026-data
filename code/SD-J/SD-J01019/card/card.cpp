#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005][7];
struct node{
	int number;
	int early;
	int flag;
}b[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[j][2]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j][1]].flag==i-1){
				b[a[j][1]].early=j;
				b[a[j][1]].flag++;
			}else{
				for(int k=b[a[j][1]].early;k<=j-1;k++){
					a[k][2]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(a[j][2]==0){
				b[a[j][1]].number++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i].number<<" ";
	}
	return 0;
}
