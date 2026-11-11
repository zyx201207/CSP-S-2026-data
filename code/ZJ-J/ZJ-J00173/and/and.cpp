#include<bits/stdc++.h>
using namespace std;
int A[200001],t1,t2,t3,n,m,b;
void two(int x){t2=10;while(t2>=1){if(x>=pow(t2,2)){A[t2]++;x-=pow(t2,2);}t2--;}if(x>=1){A[0]++;}}
int main(){
//    freopen(stdin,'r',"and.ans");
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>t1;two(t1);}
	for(int i=9;i>=0;i--){cout<<A[i]<<' ';}//  if(A[i]>=m){cout<<pow(A[i],2);}
	return 0;
} 

