#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long arr[n],mark[n];
	for(long long i=0;i<n;i++){
		cin>>arr[i];
		if(i>=n-m){
			mark[i]=1;
		}else{
			mark[i]=0;
		}
	}
	long long max=-1,s;
	do{
		int a=1;
		for(long long i=0;i<n;i++){
			if(mark[i]==1 && a==1){
				s=arr[i];
				a=0;
			}
			if(mark[i]==1 && a==0)s=s&arr[i];
		}
		if(max==-1 || s>max)max=s;
	}while(next_permutation(mark,mark+n));
	cout<<max<<endl;
	return 0;
}
