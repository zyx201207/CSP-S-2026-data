#include<bits/stdc++.h>
using namespace std;

long long n,m,f;
string v;
long long ans[1000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>m;
	
	string a;
	char c;
	for(int i=0;i<n;i++){
		cin>>c;
		a=a+c;
	}
	for(int j=0;j<n;j++){
		for(int i=j;i<n;i++){
			for(int k=0;k<v.length();k++){
				if(v[k]==a[i]){
					v.erase(k,v.length()-k);
				}
			}
			v=v+a[i];
			
		}
		for(int i=0;i<v.size();i++){
			f=v[i]-'0';
			ans[f-1]+=1;
		}
		v.clear();
	}
		
	for(int i=0;i<m;i++){
		if(i!=m-1){
			cout<<ans[i]<<" ";
		}
		else{
			cout<<ans[i];
		}
	}      
	return 0;
}
