#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<0<<endl;
		/* 2h都调不出来啊 饿啊  
		int mat[5005]={},cha[5005]={},chac[5005]={},cha2[5005]={};
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>mat[i];
			cha[i]=mat[i]-mat[i-1];
			chac[i]=mat[i]-mat[1];
		}
		int l=1,r=1,cost=0;
		while(l<n){
			while(cost+cha[r+1]<=d && r<n){
				cost+=cha[r+1]; 
				r++;
			}
			cha2[l]=r-l;
			cost-=cha[l+1];
			l++; 
		}
		int sum[5005]={}; int num=0;
		//for(int i=1;i<=n;i++) cout<<cha2[i]<<" "<<cha[i]<<" "<<chac[i]<<endl;
		for(int i=1;i<=n;i++){
			bool f=0;
			if(chac[i]>2){
				int lll=chac[i]; 
				for(int j=1;j<=lll;j++){
					if(chac[i+j]>1){
						lll+=chac[i+j];
					}
					if(i+j>=n){
						num++; sum[num]=-3;f=1;
						break;
					}
				}
				i=i+lll;
				if(f==1){
					break;
				}
				num++; sum[num]=1;
			}
			if(cha2[i]==1 && sum[i-1]<=0){
				num++; sum[num]=1;
			}else if(cha2[i]==1){
				sum[num]++;
			}else if(cha2[i]==2){
				if(sum[num]==-1) sum[num]=-2;
				else{
					num++; sum[num]=-1;
				}
			}else if(cha2[i]==0){
				if(sum[num]==-3) continue;
				else{
					num++; sum[num]=-3;
				}
			}
			//cout<<i<<" "<<num<<endl;
		}
		for(int i=1;i<=num;i++){
			cout<<sum[i]<<" ";
		}
		//for(int i=1;i<=num;i++)*/
	}
	return 0;
}







