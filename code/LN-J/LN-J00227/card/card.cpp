#include<bits/stdc++.h>
using namespace std;  
int a[200000];
long long s[200000];
int n,m;

bool ck(int k,int i){
	int l=i,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]<k){
			l=mid+1;
			}
		if(a[mid]>k){
			r=mid-1;
			
			}
		if(a[mid]==k){
			return 1;
			}
		}
	
	return 0;
	}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ck(j,i)){
				s[j]+=1;
				}
			}	
	
	
	}

	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
		}


	return 0;
}
