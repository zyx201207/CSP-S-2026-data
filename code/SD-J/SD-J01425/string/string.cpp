#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char y[200005];
	int n,x[200005];
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		
	}
	int k=0,s=0;
	for(int i=1;i<=n;i++){
		if(n+1-i-s<0||i+k>n)
			break;
		if(x[n+1-i-s]>=x[i+k]){
			while(x[n+1-i-s]>0){
				if(y[i+k]!=y[n+1-i-s])
					cnt+=min(x[n+1-i-s],x[i+k]);
				if(x[i+k]>=x[n+1-i-s]){
					x[i+k]-=x[n+1-i-s];
					x[n+1-i-s]=0;
					k--;
					break;
				}
				else{
					x[n+1-i-s]-=x[i+k];
					x[i+k]=0;
				}
					
				k++;
			}
			
		}
		if(x[n+1-i-s]<x[i+k]){
			while(x[i+k]>0){
				if(y[i+k]!=y[n+1-i-s])
					cnt+=min(x[n+1-i-s],x[i+k]);
				if(x[n+1-i-s]>=x[i+k]){
					x[n+1-i-s]-=x[i+k];
					x[i+k]=0;
					s--;
					break;
				}
				else
					x[i+k]-=x[n+1-i-s];
					x[n+1-i-s]=0;
				s++;
			}
		}
	}
	
	cout<<cnt;
	return 0;
}
