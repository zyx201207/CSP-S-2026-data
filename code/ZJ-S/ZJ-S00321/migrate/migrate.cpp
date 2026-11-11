#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
const int N = 2e6+5;
int x[N];
long long ans=0;
bool check(int u,int v){
	return true;//ke yi de ,zong si ling
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	if(c<=10){
		while(t--){
			
			ans=0;
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(check(u,v)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		//i don't know how to do it
	}else if(c<=12){
		//x1, x2, . . . , xn ???????
		while(t--){
			
			ans=0;
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(check(u,v)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		//i don't know how to do it
	}else if(c<=14){
		//??????,?????????????????????
		while(t--){
			
			ans=0;
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(check(u,v)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		//i don't know how to do it
	}else if(c<=18){
		//xn - x1 = 10d?
		while(t--){
			
			ans=0;
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(check(u,v)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		//i don't know how to do it
	}else{
		while(t--){
			
			ans=0;
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(check(u,v)){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		//i don't know how to do it
	}
	return 0;
}
