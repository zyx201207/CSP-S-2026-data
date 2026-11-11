#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans=0;
string s1,s2,s3,s4;
struct node{
	long long d;
	char s;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i].d;
		cin>>a[i].s;
	    for(int j=1;j<=a[i].d;j++){
	    	s1+=a[i].s;
		}
	}
	long long len=0;
	for(int i=s1.size()-1;i>=0;i--){
		s2[len]=s1[i];
		len++;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i])ans++; 
	}
	cout<<ans/2;
	return 0;
}
