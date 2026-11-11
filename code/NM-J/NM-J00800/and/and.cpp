#include<bits/stdc++.h>
using namespace std;
long long q[200010];
long long max_n=-1;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>q[i];
	} 
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			if(int(q[i]&q[j])>max_n&&(i!=j)){
				max_n=q[i]&q[j];
			}
		}
	} 
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			if(int(q[i])>max_n){
				max_n=q[i];
			}
		}
	}
	cout<<max_n;
	return 0;
}
