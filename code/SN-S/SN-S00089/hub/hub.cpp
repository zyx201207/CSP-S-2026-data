#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,cnt=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,x[500005];
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		cnt=0;
		if(n>=4){
			while(n==4){
				n--;
				cnt++;
				cout<<cnt<<endl;
			}
		}
	}
	return 0;
}
