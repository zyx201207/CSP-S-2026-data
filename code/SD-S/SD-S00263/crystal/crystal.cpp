#include<bits/stdc++.h>
using namespace std;
int j=0;
long long a[100000],b,m,c[100000],cnt=0,sf=0,jl,ta[1000000],xcnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>b>>m;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}  
	sort(a,a+b);
	for(int i=0;i<b;i++){
		while(1){
			cnt+=a[i]-a[j];
			j++;
			if(cnt>m){
				break;
			}
			
			
		}
		//cnt+=xcnt;
		//xcnt=0;
		//jl++;
		//ta[i]=a[i];
		if(cnt>m){
			cout<<j;
			break;	
		}else if(cnt==m){
			cout<<j-1;
			break;
		}else{
			sf=3;
		}
	}
	//if(sf==2){
		
	//}else if(sf==1){
		
	//}
	if(sf==3){
		cout<<b;
	}
	return 0;
	
} 
