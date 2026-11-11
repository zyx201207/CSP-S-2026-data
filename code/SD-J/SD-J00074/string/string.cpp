#include<bits/stdc++.h>
using namespace std;
long long z,e,n,a[100005]={0},ans1,ans2=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		string w;
		cin>>a[i];
		cin>>w;
		if(i>0&&a[i]==a[i-1]) z++;
		for(long long i=0;i<a[i];i++)
			s+=w;
	}
	long long ch=s.size()/2;
	string q=s;
	for(long long i=0;i<ch;i++){
		if(s[i]!=s[s.size()+1-i]){
			s[s.size()+1-i]=s[i];
			ans1++;
		}
	}
	for(long long i=0;i<ch;i++){
		if(q[s.size()+1-i]!=q[i]){
			q[i]=q[q.size()+1-i];
			ans2++;
		}
		if(q[0]==q[i]) e++;
	}
	if(z==n-1){
		cout<<n*a[1]/2<<endl;
		return 0;
	}
	if(e==q.size()-1) ans1=ans2=0;
	if(ans1>ans2) cout<<ans2<<endl;
	else cout<<ans1<<endl;
	return 0;
}
