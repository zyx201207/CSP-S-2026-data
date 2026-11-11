#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
int n1[200001];
long long nowans;
void dfs(long long a){
	long long tmp,lastans;
	if(a>m){
		
		ans=max(ans,nowans);
		}
	for(int i=0;i<n;i++){
		if(n1[i]!=-1){
			tmp=n1[i];
			n1[i]=-1;
			if(a==1) {
				nowans=tmp;
				lastans=0;}
			else{lastans=nowans;
				nowans=nowans&tmp;
				
				}
			dfs(a+1);
			nowans=lastans;
			n1[i]=tmp;
			
			
			
			}
		
		
		
		
		
		}
	
	
	
	
	};


int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++) cin>>n1[i];
dfs(1);
cout<<ans;
return 0;

}
