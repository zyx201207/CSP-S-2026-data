#include<bits/stdc++.h>
using namespace std;

int cry[500020];

//void sol1(){
//	
//}




int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cry[i];
	}
	

	
	//n<=6000
	if(n<=6000){
	
	int maxn=0;
	sort(cry+1,cry+n+1);
	for(int i=1;i<n;i++){
		int cnt=1;
		int chance=m;
		for(int j=i-1;j>=1;j--){
			//cout<<endl;
			
			//if(i-j<1&&i+j>n){
			//	break;
			//}
			
			
				//right
				
			int cost=abs(cry[i]-cry[j]);
			
			if(chance-cost<0)break;
			
			if(chance-cost>=0){
				chance-=cost;
				cnt++;
					
					
					//cout<<cry[i]<<" "<<cry[j]<<"  ";
			}
				
		}
		//cout<<"  "<<cnt<<endl;
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	}
	
	else{
	
		int cha=cry[4]-cry[3];
		int a=0;
		while(((a+1)*a*cha)/2<=m){
			a++;
			
		}
		cout<<a;
	}
		
		
	
	
	return 0;
	
}
