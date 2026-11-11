#include <bits/stdc++.h>
using namespace std;
long long n,a,ans; 
string c,lms=" ",ts;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			lms=lms+c;
		}
	}
	long long lmss=lms.size()-1,zjz=(lmss+1)/2;
	
	//cout<<lms<<" "<<lmss<<endl;
	//cout<<zjz<<endl;
	//for(int i=1;i<=zjz;i++){
		if(lmss%2==1){
			for(int j=1;j<zjz;j++){
				if(lms[j]!=lms[lmss+1-j]){
					ans++;
					cout<<ans<<" "<<j<<endl;
				}
			}
		}
		else if(lmss%2==0){
			for(int j=1;j<=zjz;j++){
				if(lms[j]!=lms[lmss+1-j]){
					ans++;
				}
			}
		}
	//}
	cout<<ans;
	
	
	
	
	return 0;
} 
