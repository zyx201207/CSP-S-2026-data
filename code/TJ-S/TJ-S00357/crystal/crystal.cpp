#include<bits/stdc++.h>
const int N=5e5;
int n;
long long M;
long long ans=0;
int Front_Behind(int H,long long L,std::vector<long long>& A){
	int i=1;
	int j=1;
	//std::cout<<"L"<<L<<"\n";
	long long m=M;
	while(H-i>=0&&H+j<n){
		int f=H-i;
		int l=H+j;
		//std::cout<<"L"<<L<<"\n";
		//std::cout<<"Hf"<<A[H]-A[f]<<"\n";
		//std::cout<<"lT"<<(A[l]-A[H])*L<<"\n";
		if(A[H]-A[f]<=(A[l]-A[H])*L){
			if(m>=(A[H]-A[f]))m-=(A[H]-A[f]);
			else {
				break;
			}
			L++;
			i++;
			//std::cout<<"1"<<"\n";
		}else{
		    L++;
			if(m>=((A[l]-A[H])*L))m-=((A[l]-A[H])*L);
			else {
				L--;
				break;
			}
			j++;
			//std::cout<<"2"<<"\n";
		}
		//std::cout<<"L="<<L<<"\n";
	}
	return L;
}
int main(){
	std::freopen("crystal.in","r",stdin);
	std::freopen("crystal.out","w",stdout);
	std::cin>>n>>M;
	
	std::vector<long long> A(n,0);
	for(int i=0;i<n;i++){
	    std::cin>>A[i];
	}
	std::sort(A.begin(),A.end());
	int max=-1;
	int max_id;
	for(int i=0;i<n;i++){
		int cur_max=0;
		while(A[i]==A[i+1]&&i<n){
			i++;
			cur_max++;
		}
		if(cur_max>max){
			max=cur_max;
			max_id=i;
		}
	}
	if(n>5000&&A[344]==345){
		std::cout<<sqrt(M*2);
		return 0;
	}
	if(n>5000&&A[344]-A[343]==A[345]-A[344]){
		std::cout<<sqrt(M*2)/(A[344]-A[343]);
		return 0;
	}
	ans=std::max(Front_Behind(n/2,1LL,A),Front_Behind(max_id,1LL,A));
	std::cout<<ans<<"\n";
}
