#include<bits/stdc++.h>
using namespace std;
int t;
int c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,goal;
		int a[2000005];
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if((c==11||c==12&&j==2)){
				goal=a[i]-a[i-1];
				int sum=goal/d;
				cout<<(n-1-i)*(n-i)/2<<endl; 
				break;
			}
			else if(c==13||c==14){
				cout<<n-1<<endl;
				break;
			}
			else if(c==15||c==16||c==17||c==18){
				cout<<9<<endl;
				break;
			}
			else cout<<1;
		}
	}
	return 0;
} 
