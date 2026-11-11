#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
ll n,sum=0,a1=0,ans=0;
ll j;string q;
vector<ll>a;
vector<string>b;
string x,y;
//void f(){
//	for(int i=0;i<a.size();i++){
//		cout<<a[i]<<' ';
//	}cout<<'\n';
//	for(int i=0;i<a.size();i++){
//		cout<<b[i]<<' ';
//	}
//	cout<<'\n';
//	return;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n;
	for(int i=0;i<n;i++){
		
		//cout<<1;
		cin>>j>>q;
		sum+=j;
		a.push_back(j);
		b.push_back(q);
	}
	n--;
	
	
	//cout<<"n结果："<<n<<'\n'; 
	
	
	while(1){
		x=b[a1];
		y=b[n];
		if(a[a1]==0){
//		 cout<<"左完\n";
		 a1++;
		}
		
		if(a[n]==0)n--;
		if(a1==n||a1-n>0)break;
		if(a[a1]==a[n]){
			if(x!=y){
				ans+=a[a1];
				//cout<<"我们加了"<<a[a1]<<'\n'; 
				
			}
			a[a1]=0;
			a[n]=0;
			continue;
		}
		if(a[a1]>a[n]){
			
			if(x!=y){
				ans+=a[n];
				//cout<<"我们加了"<<a[n]<<'\n'; 
			}
			//cout<<ans<<'\n';
		//	f();
			//cout<<"互减\n";
			a[a1]-=a[n]; 
			a[n]=0;
			
			//f();
			//cout<<'\n';
		}else{
			if(x!=y){
				ans+=a[a1];
				//cout<<"我们加了"<<a[a1]<<'\n'; 
			}
			//cout<<ans<<'\n';
			//f();
			//cout<<"互减\n";
			a[n]-=a[a1];
			a[a1]=0;
			//f();	
		}
	}
	
	cout<<ans;
	return 0;
} 
