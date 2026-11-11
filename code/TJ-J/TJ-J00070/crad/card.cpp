#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m;
	cin>>n>>m;
	long long a[50001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}else if(m==2){
		int k=a[n-1];
		for(int i=0;i<m;i++){
			
			if(i==k-1){
				if(i==0){
					cout<<n<<' ';
				}else{
					cout<<n;
				}
			}else{
				cout<<n/m<<' ';
			}
		}
	}else{
		int k=a[n-1];
		for(int i=0;i<m;i++){
			
			if(i==k-1){
				if(i!=m-1){
					cout<<n<<' ';
				}else{
					cout<<n;
				}
			}else{
				cout<<n/m<<' ';
			}
		}
	}
	
	return 0;
} 
