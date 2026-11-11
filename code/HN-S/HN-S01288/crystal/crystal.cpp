#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn];
long long n,m,m1;
long long num=-1;
long long rulee; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	//bool isA=true;
	long long x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(i==2) x=a[i]-a[i-1];
		//if(i>2 && isA){
		//	if(a[i]!=x+a[i-1]) isA==false;
		//}
	}
	//cout<<isA;
	if(false){
		
		
	}else{
		sort(a+1,a+1+n);
		//cout<<a[1]+1<<" "<<a[n]; 
		for(int rulee=a[1]+1;rulee<=a[n];rulee++){
			int j=1;
			long long z=rulee-a[j];
			long long num1=0;
			m=m1;
			while(z>=0 && m>=0 && j<=n){
				m-=z;
				num1++;
				j++;
				z=rulee-a[j];
			}
			num=max(num,num1);
		}
		cout<<num;
		return 0;
	}
	
	return 0;
} 
