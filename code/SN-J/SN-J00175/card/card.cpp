#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		int k=i;
		for(int j=i+1;j<=n;j++){
			if(a[k]==a[j]){
				a[j]=-1;
				cnt++;
		    }
		}
	}
	cout<<cnt;
	return 0;
}
