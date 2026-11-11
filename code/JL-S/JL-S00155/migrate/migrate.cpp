#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
    int n,d;
		int p=0;
		cin>>n>>d;
		int x[n];
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		for(int j=0;j<n/2-1;j++){
			int q=x[j];
			q+=d;
			q+=d;
			q-=1;
			if(q==x[n-1]){
				p++;
			}
		}
		cout<<p;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
