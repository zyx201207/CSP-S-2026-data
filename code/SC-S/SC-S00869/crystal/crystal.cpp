#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	int n,m,ma=-99999;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=1;
	int g=n-1;
	int t=m;
	for(int i=g;i>0;i--){
		for(int i=g;i>0;i--){
			int h=a[g]-a[i-1];
			m=m-h;
			if(m>=0){
				sum++;
				if(sum>ma){
					ma=sum;
				}	
			}
			else if(m<0) break;
		}			
		g--;
		sum=1;
		m=t;	
	}
	cout<<ma;
	return 0;
}
 