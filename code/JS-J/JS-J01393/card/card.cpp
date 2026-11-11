#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int hu[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				hu[a[i]]++;
			}
			else{
				hu[1]++;
				hu[2]++;
			}
		}
		cout<<hu[1]<<' '<<hu[2];
	}
	else{
		for(int i=1;i<=n;i++){
			hu[a[i]]++;
		}
		cout<<hu[1]<<' ';
		for(int i=2;i<=m;i++){
			hu[i]=hu[i-1]+hu[i];
			cout<<hu[i]<<' ';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
