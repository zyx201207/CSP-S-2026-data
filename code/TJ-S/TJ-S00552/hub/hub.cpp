#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long arr[9000001],ar[9000001],v[100001],jg[100001];
int main(){
	std::ios::sync_with_stdio(false);
    freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,m,n;
	cin>>c>>t;
	for(int k=0;k<t;k++){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>arr[i]>>ar[i];
			if(ar[i]>=arr[i]){
				v[i]=ar[i]-arr[i];
			}
			else{
			    v[i]=arr[i]-ar[i];	
			}
		 
		}
		sort(v,v+n);
		jg[k]=v[0];
	}
	for(int i=0;i<t;i++){
		cout<<jg[i]<<endl;
	}
	
	return 0;
} 
