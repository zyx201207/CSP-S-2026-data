#include<bits/stdc++.h>
using namespace std;
struct zu{
	long long num;char zf;
};
long long sum,ans;
vector<zu> S;//整合后的字符串 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++){//输入，整合字符串 
		long long aa;cin>>aa;sum+=aa;
		char bb;cin>>bb;
		if(i>0&&bb==S[i-1].zf){
			S[i-1].num+=aa;
		}else{
			S.push_back({aa,bb});
		}
	}
	if(S.size()>1){
	int nl=0,nr=0;long long sumn=0;
	while(sumn+S[nl].num<=sum/2){//此时nl即为分割线左边的组数，不是下标 
		sumn+=S[nl].num;
		nl++;
	}sumn=sum;
	
	if(sum%2==1){//将奇化归为偶数 
		S[nl].num--;sum--; 
	}
//	while(sumn-S[nr].num>=sum/2){//此时nr即为分割线右边的组数，不是下标 
//		sumn-=S[n-1-nr].num;
//		nr++;
//	}
	long long nnr=0,nnl=0;
	while(sum>0){
		long long aa=min(S[nnl].num,S[n-1-nnr].num);
		if(S[nnl].zf!=S[n-1-nnr].zf){
			ans+=aa; 
		}
		sum=sum-2*aa;
		S[nnl].num-=aa;S[n-1-nnr].num-=aa;
		if(S[nnl].num==0){
			nnl++;
		}else if(S[n-nnr-1].num==0){
			nnr++;
		}
	}
	cout<<ans;
	}else{
	cout<<0;
	}
	
	return 0;
} 
