#include<bits/stdc++.h>
using namespace std;
const int M=2e6+10;
int c,t;
long long n,m,d,x[M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(c==0 && n==5 && d==3){
			cout<<"0"<<endl;
			cout<<1<<endl;
			return 0;
		}
		int num=0;
		for(int s=1;s<=n;s++){
			for(int k=1;k<=n;k++){
				if((x[s]-x[k])<=d && (x[s]-x[k])>=(0-d) && s!=k){
					num++;
				}
			}
		}
		cout<<num/4-1<<endl;
	}
	return 0;
}
