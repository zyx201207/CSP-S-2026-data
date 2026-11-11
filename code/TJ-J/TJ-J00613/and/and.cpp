#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q[10001],s,sum,tt;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>q[i];
		}
		for(int i=0;i<n;i++){					
		if(sum<q[i]) sum=q[i];						
		if(q[i]==q[i-1]||q[i]==q[i-2]||q[i]==q[i-3]||q[i]==q[i-4]||q[i]==q[i-5]||q[i]==q[i-6]||q[i]==q[i-7]||q[i]==q[i-8]||q[i]==q[i-9]||q[i]==q[i-10]||q[i]==q[i-11]||q[i]==q[i-12]||q[i]==q[i-13]||q[i]==q[i-14]||q[i]==q[i-15]||q[i]==q[i-16]||q[i]==q[i-17]||q[i]==q[i-18]||q[i]==q[i-19]||q[i]==q[i-20]||q[i]==q[i-21]||q[i]==q[i-22]){
			tt=q[i];
		}

}	
if(m=1){
	cout<<sum;
}
else{
	cout<<tt;
}
return 0;
}
