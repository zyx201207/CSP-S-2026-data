#include<bits/stdc++.h>
typedef long long LL;
int n;
LL m;
LL a[500001];
LL c[500001];
LL um;
LL lj;
int num;
int maxn;
int main(){
	std::freopen("crystal.in","r",stdin);
	std::freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		
	}
	std::sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		um=0;
		lj=0;
		num=0;
		//std::cout<<"   "<<i<<std::endl;
		for(int j=i-1;j>=1;j--){
			um+=(c[j+1]+lj);
			lj+=c[j+1];
			if(um>m){
				break;
			}
			num++;
			//std::cout<<"    "<<j<<" "<<um<<std::endl;
		}
		if(num!=0) num++;
		maxn=std::max(num,maxn);
		//std::cout<<"        "<<num<<std::endl;
	}
	std::cout<<maxn;
	
	

	return 0;
}