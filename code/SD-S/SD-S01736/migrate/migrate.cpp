#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> >res( 2e6+2 , vector <int> (2e6+2));
vector<int>loc(2e6+5);
int r=0;

void cz(vector<int> loc,int n,int d){
	for(int i=0;i<n;i++){
		for(int j=i;j<=i+2;j++){
			if(loc[j]-loc[i]>d){
				res[loc[i]][loc[j]]=0;
			}
			else{
				res[loc[i]][loc[j]]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+3;j<n;j++){
			res[loc[i]][loc[j]]=0;
		}
	}
	return;
}

int judje(vector<int> loc,int n,int d){
	r=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+3;j<n;j++){
			for(int k=i+1;k<=j;k++){
				res[loc[i]][loc[j]]+=res[loc[i]][loc[k]]*res[loc[k]][loc[j]];
			}
			if(res[loc[i]][loc[j]]==2){
				r++;
				break;
			}
		}
	}
	return r;
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int n=0,d=0,c=0,t=0;
	cin>>c>>t;
	
	while(t--){
		cin>>n>>d;
		cin>>loc[0];
		if(loc[0]<0){
			int a=loc[0];
			for(int i=1;i<n;i++){
				cin>>loc[i];
				loc[i]+=a;
			}
		}
		else{
			for(int i=1;i<n;i++){
				cin>>loc[i];
			}
		}
		
		cz(loc,n,d);
		cout<<judje(loc,n,d)<<endl;
	}
	
	return 0;
} 
