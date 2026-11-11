#include<bits/stdc++.h>
using namespace std;
long long q,t,n,d,a[100000005],b[100005],sum,e,r[100005][100005],ans;
void dfs(long long l,long long c){
        if(l>=n){
                while(b[e]!=0){
					e++;
					sum++;
					}
					e=0;
				
				sum=0;
                return;
        }else{
              for(int i=0;i<=1;i++){
                  if(i==0){
                     b[c]=a[l];
                     dfs(l+1,c+1);
             }
                  if(i==1){
                     b[c]=0;
                     dfs(l+1,c);
                        }
            }
        }
        }

int main(){
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
		cin>>q>>t;
		for(int i=0;i<t;i++){
			cin>>n>>d;
			for(int j=0;j<n;j++){
				cin>>a[j];
				}
			dfs(0,0);
			cout<<ans/4;
		}
        fclose(stdin);
        fclose(stdout);
        return 0;
        }

