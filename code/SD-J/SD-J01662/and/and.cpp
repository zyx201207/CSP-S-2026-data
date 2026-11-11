#include<bits/stdc++.h> 
using namespace std;
bool num[200005][30],num1[200005];

void zh(int a,int b){
	int i=0;
	while(a!=0){	
		num[b][i]=a%2;
		a/=2;
		i++;}		
}
int a(int n){
	int x=0;
	for(int i=200004;i>=0;i--){if(num1[i]){x+=num[i][n];}}
	return x;			
}
int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	long long n,m,x,c,maxn=pow(2,31)-1;
	int d[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){num1[i]=1;}
	for(int i=0;i<n;i++){cin>>x; zh(x,i); d[i]=x;}
	

	for(int i=29;i>=0;i--){
		c=a(i);
		if(c>=m){
			for(int j=0;j<n;j++){
				if(!num[j][i]){num1[j]=0;}}}}
				
			
	for(int i=0;i<n;i++){if(num1[i]){maxn=(maxn&d[i]);}};
		
	
	cout<<maxn;	
		
		
		
		
	
	
	return 0;	
	}
		
	
	
		
		
		
		
		
		
		
	


