#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c[100005],m=0,c1[100005]={0},s=0,p=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		m=max(m,c[i]);
	}
	for(int i=0;i<=30;i++){
		if(m<pow(2,i)){
			m=i-1;
			break;
		}
	}
	for(int i=m;i>=0;i--){
		if(c[i]>=pow(2,i)){
			s++;
		}
		else{
			c1[i]=1;
		}
		if(s=b){
			for(int j=1;j<=a;j++){
				if(!c1[j]){
					
					if(p==0){
						p=c[j];
					}
					else{
						p=p&c[j];
					}
				}
			}
			cout<<p;
			return 0;
		}
		else if(s>b){
			for(int j=1;j<=a;j++){
				if(!c1[j]){
					c[j]=0;
				}
			}
		}
		else{
			for(int j=1;j<=a;j++){
				c1[j]=0;
			}
		}
		s=0;
	}
	for(int i=1;i<=a;i++){
		if(!c1[i]){
			//cout<<c[i]<<" ";
			if(p==0){
				p=c[i];
			}
			else{
				p=p&c[i];
				b--;
				if(b==0){
					cout<<p;
					return 0;
				}
			}
		}
	}
	return 0;
}