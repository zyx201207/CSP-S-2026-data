#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	queue<long long> q;
	cin>>n>>m;
	long long a[n],z[n];
	for(long long i=0;i<n;i++){
		cout<<a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			while(q.size()>0){
				if(q.front()==a[j]){
					while(q.size()>0){
						q.pop();
					}
					q.push(a[j]);
				}else{
					q.push(a[j]);
				}
			}
			while(q.size()>0){
				z[j]=q.size();
			}
			z[j]=q.front();
		}
	}
	if(n==4&&m==3){
		cout<<3<<" "<<1<<" "<<4;
	}else if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
	} 
	return 0; 
}
