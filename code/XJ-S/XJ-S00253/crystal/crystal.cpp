#include<bits/stdc++.h>
using namespace std;
long long n,m;//n数量 m最多次数 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+1],mix,mixc,b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//问:m次操作后最多有多少个能量相同的水晶 
	sort(a+1,a+n+1); //排序 
	//骗性质AB:五点 
	for(int i=1;i<=n;i++){
		mixc+=a[i];
		mix=a[i]*i;
		if(mix-mixc==m){
			cout<<i;
			break;
		}
	}
	
	//无性质
	 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

