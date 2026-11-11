#include<bits/stdc++.h>
using namespace std;
int n,ans[300004],m,pai[500004],wei[300004],a;
string c,l;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>pai[i];
		int i=1;
	    while(i<=n){
		int fang=1;
		for(int j=i;j<=n;j++){
			if(wei[pai[j]]==0){
				wei[pai[j]]=fang;
				fang++;
			    }else{
			        fang=wei[pai[j]]+1;
			        for(int q=1;q<=m;q++){
						if(wei[q]>=fang) wei[q]=0;
					}
		        }
		    }
		    for(int q=1;q<=m;q++){
				if(wei[q]!=0){
					ans[q]++;
					wei[q]=0;
				}
			}
			i++;
		}
	for(int q=1;q<=m;q++){
			cout<<ans[q]<<" ";
			}
	
    		
}




