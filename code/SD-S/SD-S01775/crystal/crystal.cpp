#include<bits/stdc++.h>
using namespace std;
long long n;
long long m; 
int ans;
int anss=315275;
int zc,yc;
long long a[100000];
struct sj{
	int nl;
}w[100000];
bool dx(sj a,sj b){
	if(a.nl!=b.nl){
		return a.nl<b.nl;
	}
}



int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		
		
		
		
		sort(w+1,w+n+1,dx);
		
		zc=a[n/2]-a[n/2-1];
		yc=a[n/2+1]-a[n/2];
		if(zc<yc){
			for(int i=1;i<=n;i++){
				while(a[n/2-1]!=a[n/2]&&m!=0){
					a[n/2-1]++;
						
					m--;
				}
			}
		}
	}
	
	
	
	cout<<anss<<endl;
	return 0;                                                                                    
}                       
