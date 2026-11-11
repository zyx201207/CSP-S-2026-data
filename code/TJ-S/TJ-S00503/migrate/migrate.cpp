#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long text,num;
	cin>>text;
	cin>>num;
	int ans[num];
	for(int i=1;i<=num;i++){
		int n,d;
		cin>>n;
		cin>>d;
		int jl[n];
		for(int i=0;i<=n-1;i++){
			cin>>jl[i];
		}
		for(int j=0;j<=n-1;j++){
			for(int k=j+1;k<=n-1;k++){
				int min=0,cnt=0,now=j;
				while(now!=k){
					for(int dao=0;dao<=n-1;dao++){
						if(max(jl[now]-jl[k],jl[k]-jl[now])>max(jl[dao]-jl[k],jl[k]-jl[dao])){
							now=dao;
							cnt=cnt+1;
						}
					}
				}
				
			}
		}
	}
	return 0;
}
