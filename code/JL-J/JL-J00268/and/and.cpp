#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int s(const int &x){
	int t=x,sum=0;
	while(t){
		sum+=t%2;
		t>>=1;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ss=0,ma=-1;
	for(unsigned long long i=0;i<pow(2,n);i++){
		if(s(i)==m){
			ss=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					if(ss==0){
						ss=a[j];
					}
					ss&=a[j];
				//	cout<<a[j]<<" ";
				}
			}
			ma=max(ma,ss);
			//cout<<ss;
			//cout<<endl;
		}
	}
	cout<<ma<<endl;
	return 0;
}
