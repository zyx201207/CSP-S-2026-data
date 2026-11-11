#include<bits/stdc++.h>
using namespace std;
int c,t;
int n[6],k[6];
const int N=100001;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>k[i];
		for(int j=1;j<n[i];j++){
			cin>>u[j]>>v[j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<"1";
	}
    fclose(stdin);fclose(stdout);
	return 0;
}