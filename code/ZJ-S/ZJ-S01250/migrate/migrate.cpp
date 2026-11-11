#include<bits/stdc++.h>
#define ll long long 
const int N=2e6+5;
int c,t;
ll a[N];
int n,d;
int ans=0;
ll ans_t=0x3f3f3f3f;
void dfs(int now,int t,int des){
	
    if(now==des){
    	if(t<ans_t){
    		ans_t=t;
    		ans=1;
		}else if(t==ans_t){
			ans++;
		}
        return ;
    }
    for(int i=now+1;i<=des;i++){
    	if(a[i]-a[now]>d){
    		return ;
		}
		dfs(i,t+1,des);
		
	}
    
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    
    while(t--){
        int res=0;
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
        	for(int j=i+1;j<=n;j++){
        		ans=0;
        		ans_t=0x3f3f3f3f;
        		dfs(i,0,j);
        		if(ans==2){
        			res++;	
				}
			}
		}
        printf("%d\n",res);
    }




    return 0;
}