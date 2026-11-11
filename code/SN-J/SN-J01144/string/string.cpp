#include <bits/stdc++.h> 
using namespace std;
int n,ans=0,a,k=0,p=0;
string c,d,e,b,f;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a>>b;
		for(int j = 0;j<a;j++){
			k++;				
			c[k]==b[0]; 
		}
		
	}
	if(c.size()%2==0){
		for(int i = 0;i<c.size()/2;i++){
			d[i]==c[i];
		}
		for(int j = c.size()/2;j<c.size();j++){
		e[j]==c[j];
		}
		for(int t =c.size()-1;t>c.size()/2;t++){
			f[p]==e[t];
		p++;
		}	
		}
	if(c.size()%2==1){
		for(int i = 0;i<c.size()/2;i++){
		d[i]==c[i];
		}
		for(int j = c.size()/2;j<c.size();j++){
			e[j]==c[j];
		}
		for(int j =c.size();j>c.size()/2;j++){
			f[p]==e[j];
		p++;
			
	}
	}
	
	
	for(int i = 0;i<c.size()/2;i++){
		if(d[i]!=f[i]){
			ans++;
				}
			}
	cout<<ans;
	

	
	return 0;
}


