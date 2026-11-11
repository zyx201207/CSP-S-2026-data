#include <bits/stdc++.h>
using namespace std;
int n;
long long a,ans=0;
string f;
char c;
int main(){
//	freopen("string","r",stdin);
//	freopen("string","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int k=1;k<=a;k++){
			f+=c;
		}
	}
	if(f[0]!=f[f.size()-1])ans++;
	for(int i=1;i<f.size()-2;i++){
		if(f[i]!=f[f.size()-i])ans++;
	}	
	                            
	cout<<ans;    
	return 0;       
}
	