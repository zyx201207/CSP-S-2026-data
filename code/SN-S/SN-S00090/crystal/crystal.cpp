#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long v[n],x[n],tb=0,js=0,ans=0,jxb[n],ans2=0;
	for(long long i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v,v+n);
	for(long long i=0;i<n;i++){
		x[i]=v[n-1]-v[i];
		
	}
	for(long long i=v[0];i<=v[n-1];i++){
		tb=0;
		js=0;
		for(long long j=0;j<n;j++){	
			x[j]--;
			if(x[j]>0){
				tb+=x[j];
				
				jxb[js]=v[j];
				js++;
			}
			if(tb==m){
				long long hh=0;
				for(long long k=0;k<=js;k++){	
					hh+=jxb[k];
				}
				hh=(hh+m)/(js+1);				
				long long rr=0;
				for(long long k=0;k<n;k++){
					if(jxb[rr]==v[k] and rr<=js){
						ans++;
						rr++;
					}
					else if(v[k]==hh){
						ans++;
					}
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
