#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int x=0;
	int a[10005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<m;j++){
		if(a[j]+a[j]==a[j+1]){
			x=x+1;
		}
/*		else{
			if(a[j+2]+a[j+2]==a[j+3]){
				x=x+1;
			}
		}*/
			
	}
		
	cout<<x<<endl;	
	



	fclose(stdin);
	fclose(stdout);
	return 0;
}
