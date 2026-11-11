#include<iostream>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long a[5001]={};
	long long n,m;
	int c,cnt=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	int i=1; 
	for(int b=i;b>0;b--){
		cnt+=a[i+1]-a[b];
		if(cnt==m){
			c=i+1;
			return 0;
		}
		else{
			cnt=0;
			i++;
		}
	}
	if(a[c]==a[c+1]) cout<<c+1;
	else cout<<c;

	return 0;
}
