#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int l[1000010][2];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>l[j][1]>>l[j][2];
		}
	}
	return 0;
}
