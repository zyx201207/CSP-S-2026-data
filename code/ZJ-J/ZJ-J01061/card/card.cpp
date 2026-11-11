#include<bits/stdc++.h>
using namespace std;
long long many,ni,pai[300010],pai_2[300010],pai_flag[300010],vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>many>>ni;
	for(int i=1;i<=many;i++){
		cin>>pai[i];
	}
	long long zz=1;
	for(int j=1;j<=many;j++){
		for(int i=j;i<=many;i++){
			bool flag=false,flag_2=false;
        for(int k=1;k<=zz;k++){
        	if(pai_2[k]==pai[i]){
        		flag=true;
        		if(flag_2==false){
       			zz=k-1;        			
				}
        		flag_2=true;
        		break;
			}
		}
		zz+=1;
		pai_2[zz]=pai[i];
		}
		for(int i_2=1;i_2<=zz;i_2++){
			pai_flag[pai_2[i_2]]+=1;
		}
		for(int i=1;i<=zz;i++){
			pai_2[i]=0;
		}
		zz=1;
	}
	for(int i=1;i<=ni;i++){
		cout<<pai_flag[i]<<" ";
	}
	return 0;
}

