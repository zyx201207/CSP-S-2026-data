#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t,n[110],d[110],x[110],k,l[110]={},p[110];
    cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[j];	
		}
	} 
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			if(x[j]+1!=x[j+1]){
				n[i]--;
			}	
		}
	} 
	for(int i=1;i<=t;i++){
			p[i]=n[i]/d[i];		
	}
	for(int i=1;i<=t;i++){
		k=n[i];
		for(int j=d[i];j>=1;j--){
			
			if(k%j==0&&k/j==p[i]){
				l[i]++;
			}
			else if(k%j!=0){
				k=k-j;
			if(k<=j+1&&k+1==p[i]){
				l[i]++;
			}
			else for(int i=1;i<=t;i++){
			if(k%j!=0){
				k=k-j;
			if(k<=j+1&&k-n[i+1]==(n[i]-1)/d[i]){
				l[i]++;
			}
		} 
		}
		}
		}
	}
	for(int i=1;i<=t;i++){
		if(p[i]%2==0){
		cout<<p[i]/2<<endl;
	}
	else{
		cout<<"0"<<endl;
	}
	}
return 0; 
}


