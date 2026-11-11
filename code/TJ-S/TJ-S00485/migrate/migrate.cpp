#include<bits/stdc++.h>
using namespace std;
long long c,t,n,ff,cnt,d;
long long a[1001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		//cout<<t;
		
		cnt=0;
		ff=0;
		cin>>n>>d;
		for(long long i=0;i<n;i++){
			cin>>a[i];
				cnt=a[1];
			if(a[1]>cnt+d&&i!=0){
				ff=i;
			}
		}
		if(a[1]-a[0]<=d){
		cout<<0;
		cout<<endl; 
		//cout<<"js";
		goto uu;
		}
	//	cout<<"uuu";
		cout<<n-ff+1;
		cout<<endl;
		uu:{
		}
	}
	}
	
	
	

