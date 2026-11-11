#include<bits/stdc++.h>
using namespace std;
int n,a[200010],z,ans,d;
string b[200010],s1,s2;
bool y=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s1+=b[i];
		}
	}
	z=s1.size()/2;
	d=s1.size();
	for(int i=0;i<z;i++){
		if(s1[d-i-1]!=s1[i]){
			y=0;
		}
	}
	if(y==1){
		cout<<"0";
		return 0;
	}
	
	for(int i=0;i<z;i++){
		if(s1[d-i-1]!=s1[i]){
			ans++;
		}
	}
	cout<<s1<<endl;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
