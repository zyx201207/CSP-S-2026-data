#include<bits/stdc++.h>
using namespace std;
long long po(int a,int b){
	int ans1=1,i=1;
	for(i=1;i<=b;i++){
		ans1*=a;
		
	}
	if(i>b)return ans1;
}
int main(){
	int a,b,n,ans,m,num,p1,p2,min=INT_MAX;
	cin>>a>>b; //0010,1111 0010 0010,1100 0000  1110 1100 1100 
	int s[a]={0},c[a]={0},jg[a]={0};
	for(int i=0;i<a;i++){
		cin>>num;
		n=num;
		ans=1;
		while(n){
			s[i]+=(n%2)*ans;
			ans*=10;
			n/=2;
			c[i]++;
		}
		//cout<<s[i]<<endl;
	}
	for(int i=a-1;i>0;i--){
		m=c[i];
		//cout<<c[i]<<endl;
		for(int j=m;j>0;j--){
			//while(m>c[i-1]){
			//	m--;
			//}
			p1=po(10,m);
			p2=po(10,m-1);
			for(int k=0;k<i;k++){
			
				if((s[i]%(p1)/(p2) and (s[k]%(p1)/(p2)))){
					jg[i]+=po(2,m-1);
					//if(jg[i]<min)min=jg[i];
				}
			}
			//1001 1101 
			m--;
			
			//cout<<s[i]%(p1)/(p2)<<' '<<(s[i-1]%(p1)/(p2))<<endl;
			
		}	
		if(jg[i]<min)min=jg[i];
	}
	//for(int i=1;i<a;i++){
	//	cout<<jg[i]<<endl;
	//}
	cout<<min;
	return 0;
}
