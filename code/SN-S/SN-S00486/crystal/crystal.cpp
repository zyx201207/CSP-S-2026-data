#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
long long m;
int n;
long long num_list[N];
int num_crystal=1;
int mx;
//李星宇 SN-S00486 陕西省西安中学 
int main(){
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num_list[i]);
	}
	sort(num_list+1,num_list+1+n);
	long long value=m;
	if(n==1){
		cout<<1;
	}
	else{
		for(int i=2;i<=n;i++){
			int j=i;
			value=m;
			num_crystal=1;
//			cout<<j<<" ";
			while(value>=0&&j>1){
				if(value-(num_list[i]-num_list[j])<=0){
					break;
				}
				j--;
				value-=(num_list[i]-num_list[j]);
//				cout<<j<<":"<<num_list[i]-num_list[j]<<"当前m："<<value<<" ";
				
				num_crystal++;	

			}
			/*
			if(value>=num_list[i]-num_list[j]&&value>=0){
				value-=(num_list[i]-num_list[j]);
				cout<<j<<":"<<num_list[i]-num_list[j]<<"当前m："<<value<<" ";
				num_crystal++;			
			}
			*/
//			cout<<endl;
//			cout<<"本轮水晶："<<num_crystal<<"颗\n";
			mx=max(num_crystal,mx);
		}
		printf("%d",mx);	
	}
	return 0;
}
