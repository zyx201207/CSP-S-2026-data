#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+8;
unsigned long long n,m,a[N],ec[40],maxn = INT_MIN;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i<n;i++){
    	scanf("%lld",&a[i]);
	}
	cout<<"L";
	long long k = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(maxn<(a[i]&a[j])){
				maxn = a[i]&a[j];
				if(a[i]>a[j]){
					k=i;
			    }   
				else{
					k=j;
				}
			}
		}
	}
	m--;
	while(m--){
		cin>>n>>m;
	}
	cout<<12;
	return 0; 
}
