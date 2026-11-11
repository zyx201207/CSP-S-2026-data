#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	long long a[20005];
	long long s=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0){
			s+=0-a[i];
			a[i]=0;
		}
	}     
	long long s1=m-s;
	sort(a,a+n);  
	long long cnt=a[1]-a[0];
	long long s2=s1-cnt;
	if(s2>0){
		int cc=s2/a[2];
		for(long long i=0;i<n;i++){
			if(a[i]==a[2]){
				cc++;
			}
		}
		cout<<cc;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	return 0;
}