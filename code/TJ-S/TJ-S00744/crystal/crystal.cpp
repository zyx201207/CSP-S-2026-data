#include<bits/stdc++.h>
using namespace std;
int a[500010],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,cnt=0,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=a[1]; i<=a[n]; i++){
		int z=m;
		cnt=0; 
		for(int j=1; j<=n; j++){
			if(a[j]<=i){
				z=z-(i-a[j]);
				cnt++;
			}
		}
		if(z>=0){
			maxn=max(maxn,cnt);
		}
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
