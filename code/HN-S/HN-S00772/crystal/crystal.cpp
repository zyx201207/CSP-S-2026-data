#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,sum,cnt;
long long a[N],b[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	for(int i=0;i<n;i++){
		b[i]=abs(a[i]-sum);
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		m-=b[i];
		if(m<0){
			break;
		}else{
			cnt++; 
		}	
	}
	cout<<cnt;
	return 0; 
}
//
