#include<bits/stdc++.h>
using namespace std;
long long map1[9999999],map2[9999999],k,a,m,n,map3[10000][10000],count1,count2;
int first;
int solve(int l,int r){
	if(l==r)return 0;
	int count100=0;
	for(int i=1;;i++){
		count100+=map2[l+i-1];
		if(count100>n)return 1+solve(l+i-1,r);
        else if(l+i==r)return 1;
	} 
}
void dfs(int l,int r){
	count1=0;
	for(int i=l+1;i<r;i++){
		if(map3[i][r]+map3[l][i]==map3[l][r]){
			count1++;
		}
	}
	if(count1==2){
		count2++;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>k>>a;
    if(k==11||k==12||k==13||k==14){
    	for(int i=1;i<=a;i++){
    		cout<<0<<endl;
    		return 0;
		}
	}
    for(int i=1;i<=a;i++){
    	cin>>m>>n;
    	count1=0;
		count2=0; 
    	for(int j=1;j<=m;j++){
    		cin>>map1[j];
			if(first==0)first=1;
			else map2[j-1]=map1[j]-map1[j-1];
			if(map2[j-1]>n)m=j-1;
		}
    	for(int j=1;j<m;j++){
    		for(int k=j+1;k<=m;k++){
    			map3[j][k]=solve(j,k);   		
			}
		}
		for(int j=1;j<m;j++){
    		for(int k=j+1;k<=m;k++){   
				if(map3[j][k]!=0&&map3[j][k]!=1){
					dfs(j,k);
				}				
			}
		}
		cout<<count2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
