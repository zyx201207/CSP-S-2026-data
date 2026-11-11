#include<bits/stdc++.h>
using namespace std;
string f(long long b){

	string r="000000000000000000000000000000";
	int k=29;
	while(b>0){
		if(b%2==1){
		r[k]='1';	
		}
		
		b=b/2;
		k--;
	}
	return r;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	int k1=0;
	
	cin>>n>>m;
	string a[n];
	long long c[n];
	int v1[n];
	long long result;
	
	
	int k3=n;
	for(int i=0;i<n;i++){
		cin>>c[i];
		a[i]=f(c[i]);
		
	}
	int v3[n];
	for(int i=0;i<n;i++){
		v3[i]=i;
	}
	for(int i=0;i<30;i++){
	
	
			if(k1>=m){
				k3=k1;
				for(int g=0;g<k3;g++){
					v3[g]=v1[g];
				}
				
				k1=0;
				for(int j=0;j<k3;j++){
					if(a[v3[j]][i]=='1'){
						v1[k1]=v3[j];
						k1++;
					}
				}
			}else{
				
				k1=0;
				for(int j=0;j<k3;j++){
					if(a[v3[j]][i]=='1'){
						v1[k1]=v3[j];
						k1++;
					}
				}
			}
	}
	result=c[v1[0]];
		for(int i1=0;i1<k3;i1++){
		
			result=result&c[v1[i1]];
		}
	 cout<<result;
	return 0;
}
