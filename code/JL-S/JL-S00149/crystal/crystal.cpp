#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int n[i];
		cin>>n[i];
		for(int i=1;i<=n[i-2];i++){
			n[0]++;
			if(n[0]==n[i-2]){
				break;
			}
			
		}
		for(int i=1;i<=n[i-2];i++){
			n[1]++;
			if(n[1]==n[i-2]){
				break;
			}
			
		}
		if(n[i+1]==n[i]){
			sum++;
		}
	}
	sum+=3;
	cout<<sum;
	return 0;
}
