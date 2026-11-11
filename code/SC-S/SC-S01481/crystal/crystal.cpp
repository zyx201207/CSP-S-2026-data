#include <bits/stdc++.h>
int ele[100002];
int n,m,fin,mid,sum,ne;
void swap(int &bi,int &sma){
	mid=bi+sma;
	bi=mid-bi;
	sma=mid-sma;
}
int te(int u,int &sum){
	if(u == sum){
		sum++;
		return sum;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	for(int i=0;i<n;i++){
		std::cin>>ele[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(ele[i-1] > ele[i]){
				swap(ele[i-1],ele[i]) ;
			} 
		}
	}
	sum=ele[0];
	while(m--){
		fin = te(ele[ne],sum);
		if(fin == 0){
			if(ne > n) break;
			else{
				ne++;
				m++;
			}
		}
	}
	std::cout<<sum;
	return 0;
}