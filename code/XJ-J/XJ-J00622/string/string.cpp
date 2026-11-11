#include<bits/stdc++.h>
using namespace std;

struct stn{
	long long  ln;
	char zm;
}a[300010];
int rv;
string st="";;
int main(){
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,zz=0;
	cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i].ln>>a[i].zm;
			for(int j=0;j<a[i].ln;j++){
				st+=a[i].zm;
				
			}
		}

		if(st.size()==0||st.size()==1){
			cout<<0;
			return 0;
		}
		if(st.size()%2==1){
			long long ls=0,ans=0;;
			for(long long i=st.size()/2+1;i<st.size();i++){
				if(st[i]==st[i-ls]){
					
				}else {
					ans++;
					
				}
				ls+=2;
			}
			cout<<ans;
		}else {
			long long ls=1,ans=0;;
			for(long long i=st.size()/2;i<st.size();i++){
				if(st[i]==st[i-ls]){
					
				}else {
					ans++;
				}
				ls+=2;
			}
			cout<<ans;
		}
		//cout<<st;
		
	
	return 0;
} 
