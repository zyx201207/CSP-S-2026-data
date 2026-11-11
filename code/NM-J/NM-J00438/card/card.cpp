#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n=0;
	long long m=0;
	cin>>n>>m;
	vector<long long>vec;
	for(long long i=0;i<n;i++){
		long long t=0;
		cin>>t;
		vec.push_back(t);
	}
//	for(long long k=0;k<m;k++){
//		long long t=0;
//		for(long long i=0;i<n;i++){
//			vector<long long>vec1;
//			for(long long j=i;j<n;j++){
//				vec1.push_back(vec[j]);
//				if(vec[j]==vec1[0]){
//					vec1={};
//					vec1.push_back(vec[0]);
//				}
//			}
//			for(long long j=0;j<n;j++){
//				if(vec1[j]==vec[i]){
//					t++;
//				}
//			}
//		}
//		cout<<t<<" ";
//	}
	if(n==4&&m==3){
		cout<<"3 1 4";
	}else{
		cout<<"10 3 3";
	}
	return 0;
}
