#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  m,n,q[200002],w=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	for(int i=0;i<n;i++){
		if((q[1]&&q[i+1])>=w){
			w=q[1]&&q[i+1];
		}
	}
	cout<<w;
}
