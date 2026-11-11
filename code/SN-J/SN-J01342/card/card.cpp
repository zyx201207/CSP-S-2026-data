#include<bits/stdc++.h>
using namespace std;

int n,m,ans[500005];
char a;
string s;
bool p[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s+=a;
	}
	int b=s[n-1]-'0';
	
	for(int i=0;i<n-1;i++){
		string sw;
		for(int k=0;k<n;k++){
			p[k]=0;
		}
		for(int j=i;j<n;j++){
			
			if(p[s[j]-'0']==0){
				p[s[j]-'0']=1;
				sw+=s[j];
			}
			else {
				for(int z=0;z<sw.size();z++){
					string swe;
					if(sw[z]==s[j]){
						sw=swe;
						z=sw.size();
					}
					else swe+=sw[z];
				}
				
				sw+=s[j];
			}
		}
		
		for(int l=0;l<sw.size();l++){
			ans[sw[l]-'0']++;
		}
		
	}
	ans[b]++;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	
	return 0;
} 
