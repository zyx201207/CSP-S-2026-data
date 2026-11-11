#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,cnt;
		cin>>n>>d;
		long long last=0;
		for(int i=1;i<=n;i++){
			long long aa;
			cin>>aa;
			cnt=aa-last;
			last=aa;
		}
		d-=cnt-1;
//		cout<<d<<" "<<cnt<<endl;
		if(d<=1){
//			cout<<"!!"<<endl;
			cout<<0<<endl;
		}
		else{
			if(n-d-1>=0){
				cout<<n-d-1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		} 
	}
}
