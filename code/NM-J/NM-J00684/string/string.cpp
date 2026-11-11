#include<bits/stdc++.h>
using namespace std;


const int N=5*1e5;
long long a[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int p=1;
//	cout<<"N:"<<n<<endl;
	for(int i=1;i<=n/2+1;i++){
//		cout<<"i:"<<i<<" ";
		if(a[p]==0) p+=1;
		if(c[p]==c[n-i+1]){
			if(a[p]<a[n-i+1]) swap(a[p],a[n-i+1]);
			a[p]-=a[n-i+1];
			a[n-i+1]=0;
//			cout<<"J:";
		}
		if(c[p]!=c[n-i+1]){
			//TODO
			if(a[p]<a[n-i+1]){
				swap(a[p],a[n-i+1]);
				swap(c[p],c[n-i+1]);	
			}
			a[p]-=a[n-i+1];
			ans+=a[n-i+1];
		
//			cout<<c[p]<<" "<<a[p]<<"¡¡"<<c[n-i+1]<<" "<<a[n-i+1]<<"ans:"<<ans<<endl; 
			a[n-i+1]=0;
//			cout<<"AP:"<<a[p]<<" ";
			
			
		}
//		cout<<"ansnow:"<<ans<<endl;
	}
		
	cout<<ans;
	
	
	return 0;
} 
