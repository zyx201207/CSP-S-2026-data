#include<bits/stdc++.h>
using namespace std;
vector<int> v(500005);
int a[500005];
int have[500005]; 
int check(int i,int a){
	for(int j=i-1;j>=1;j--){
		if(v[j]==a){
			return j;
		}
	}
	return -1;
}
void clean(int i,int j){
	for(int k=j+1;k<=i;k++){
		v[k]=0;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(j,a[j])==-1){
				v[j]=a[j];
			}else{
				int k=check(j,a[j]);
				clean(j-1,k);
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(v[k]==j){
					have[j]++;
					break;
				}
			}
		}
		clean(n,0);
	}
	for(int i=1;i<=m;i++){
		cout<<have[i]<<" ";
	}
	return 0;
}