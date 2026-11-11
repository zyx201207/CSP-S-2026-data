#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k>mx){
				mx=k;
			}
		}
		cout<<mx;
	}
}

