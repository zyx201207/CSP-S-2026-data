#include<bits/stdc++.h>
using namespace std;
int d,sum;
int suan(int a,int b){
	if(b-a-(ceil((b-a)/d))==2) return 1;
	else if(b-a-(ceil((b-a)/d))<2) return 0;
	return 2; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>d;
		int a[n+1],b[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mid=ceil(n/2),l=1,r=n;
		while(r>mid&&l<mid){
			if(suan(a[l],a[r])==1){
				sum++;
				break;
			}else if(suan(a[mid],a[r])==0){
				l=mid;
				mid=ceil((l+r)/2);
			}else{
				r=mid;
				mid=(l+r)/2;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 
