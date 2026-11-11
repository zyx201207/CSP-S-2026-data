#include<bits/stdc++.h>
using namespace std;
string a;
int n,g;
char c,nc;
bool flag=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>g>>c;
		if(i!=0&&c!=nc){
			flag=1;
		}else if(i==0) nc=c;
		while(g--){
			a+=c;
		}if(flag==0){
			cout<<"0\n";
		}else{
			string ab,ac;
			for(int i=a.size()-1;i>=a.size()/2;i--){
			
				ab+=a[i];
			}
				for(int i=a.size()-1;i>=a.size()/2;i--){
				ab+=a[i];
			}
		}
			int ans;
			for(int i=a.size()-1;i>=n/2;i++)	
			ans++;
			}cout<<ans<<"\n";
		}
	}
	
