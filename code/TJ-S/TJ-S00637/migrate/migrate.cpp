#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,l[100000001],r[1000000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>l[i];
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++){
				if(l[j]-l[i]<=m){
					r[i]++;
				}
			}
		}
	}
	return 0;
}
