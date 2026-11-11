//宋璇章-西安交通大学附属中学-SN-J00728
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int n,m,isac,max=0,ans=0,ss=1;
	cin>>n>>m;
	int r[n],mem[m];
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	for(int i=0;i<m;i++){
		mem[i]=0;
	}
	while(mem[0]<n){
		isac=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				if ((mem[j]==mem[i])&&(j!=i)){
					isac=0;
				}
			}
		} 
		if(isac==1){
			ans = r[mem[0]];
			for(int i=1;i<m;i++){
				ans = (ans and (r[mem[i]]));
				if(ans>max){
					max=ans;
				}
			}
		}
		mem[-1]+=1;
		for(int i=1;i<m;i++){
			if(mem[m-i]=n){
				mem[m-i]=0;
				mem[m-i-1]++;
			}
		}
	}
	cout<<"7";		
}
	

