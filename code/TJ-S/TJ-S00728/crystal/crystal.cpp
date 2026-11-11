#include<bits/stdc++.h>
using namespace std;
const int N=1e12+10;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[100005];		
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int qym=0;
	int qq=0;
	for(int i=0;i<n;i++){
		if(m==0){
			if(a[i]=a[i+1]){
				qq++;
			}else{
				qq=1;
				
			}
			cout<<qq;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		sort(a,a+n);
		if(a[i]==a[i+1]){
			qym++;
			i++;
		}else{
			continue;
		}
		if(m>=0){
				m=m-i*(a[i+1]-a[i]);
				qym++;
				i++;
		}
	}
	cout<<qym+1;	
	return 0;
} 
