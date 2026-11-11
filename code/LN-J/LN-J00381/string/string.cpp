#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,k=0;
	cin>>n;
	string t="";
	for(int i=1;i<=n;i++){
	    long long a;
	    char b;
	    cin>>a>>b;
	    k+=a;
	    for(int j=1;j<=a;j++)
	    t+=b;	
	}
	long long ans=0;
	string s1,s2;
	if(k%2==0){
	for(int i=0;i<k/2;i++){
		s1+=t[i];
	}
	for(int i=k-1;i>=k/2;i--){
		s2+=t[i];
	}
	for(int i=0;i<=k/2;i++){
		cout<<s1[i]<<' '<<s2[i]<<"\n"; 
		if(s1[i]!=s2[i])
		ans++;
	}
	}else{
    for(int i=0;i<k/2;i++){
		s1+=t[i];
	}
	for(int i=k-1;i>=k/2;i--){
		s2+=t[i];
	}
	for(int i=0;i<=k/2-1;i++){
		if(s1[i]!=s2[i])
		ans++;
	}
	}
	cout<<ans;
    return 0;
}
