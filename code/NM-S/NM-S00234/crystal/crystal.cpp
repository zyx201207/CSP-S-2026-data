#include<bits/stdc++.h>
using namespace std;
bool fun(long long a,long long b){
	return a<b;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;
	scanf("%lld %lld",&m,&n);
	vector<long long> x(m);
	for(long long i=0;i<m;i++){
		cin>>x[i];
	}

	sort(x.begin(),x.end(),fun);
//	for(long long i=0;i<m;i++){
//		cout<<x[i]<<" ";
//	}
	int inm=0;
	if(m%2==0){
		inm=m/2+1;
	}else{
		inm=ceil(m/2.0);
	}
	inm--;
//	cout<<x.at(inm)<<" "<<inm<<" ";

//	while(1){
//		if(x[inm]==x[inm-1]){
//			if(inm+1>m){
//				break;
//			}else{
//				
//				inm++;
//			}
//		}else{
//			break;
//		}
//	}
	long long ind=inm-1;
	if(ind<0){
		ind++;
	}
	
	while(1){
		if(n==0){
			break;
			
		}
		if(x[ind]<x[inm]){
			x[ind]++;
			n--;
		}else{
			if(ind-1<0){
				if(n!=0){
				inm++;
				ind=inm-1;
			}else{
				break;
			}
				
			}else{
				ind--;
			}
		}
	}
	vector<int> an;int sum=1;
	for(int i=0;i<x.size();i++){
		if(i+1>x.size()){
			break;
		}
		if(x[i]==x[i+1]){
			sum++;
		}else{
			
			an.push_back(sum);
			sum=1;
		}
	}
	int mx=0;
	for(int i=0;i<an.size();i++){
		if(mx<an[i]){
			mx=an[i];
		}
	}
	cout<<mx;
	return 0;
}
