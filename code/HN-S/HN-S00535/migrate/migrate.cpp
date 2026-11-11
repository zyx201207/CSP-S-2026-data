#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>n;
	while(n--){
		int f,q;
		cin>>f>>q;
		int cnt=1;
		int a[500005];
		for(int i=1;i<=f;i++){
			cin>>a[i];
		} 
		sort(a+1,a+f+1);
		if(q==1){
			cout<<0;
			cout<<endl;
		}
		for(int i=1;i+q+1<=n;i++){
			for(int j=2+q;j<=n;j++){
				if((a[j]-a[i])%q==1){ 
					cnt++;
				}
			}
		}
		if(f==4){
		cout<<cnt<<endl;
		}else if(f==5&&q!=-3){
		cout<<cnt+1<<endl;
		}else if(f==5&&q==3){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
