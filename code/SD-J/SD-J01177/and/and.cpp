#include<bits/stdc++.h>
using namespace std;
int a[200010],ma=-1,s=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	ma=-1;
	if(m==n){
		s=a[1];
	for(int i=2;i<=n;i++){
		s=s&a[i];
	}
	    cout<<s;
	    return 0;
 }
    if(m==2){
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
    			ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
    s=a[n]; long long t=1;
    
	for(int i=n-1;i>=1;i--,t++){
		if(t==m){
			break;
		}
		s=s&a[i];
	}
	cout<<s;

	return 0;
} 
