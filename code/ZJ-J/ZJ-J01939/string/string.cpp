#include<bits/stdc++.h>
using namespace std;
struct node{
    int c;
    char a;
}p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//freopen("string3.in","r",stdin);
	//freopen("string3.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	bool ok=false;
	int ok1=0;
	string s;
	for (int i=1;i<=n;i++){
		cin>>p[i].c>>p[i].a;
		sum+=p[i].c;
		
		if (p[i].c!=p[i-1].c && i!=1){
			ok=true;
		}
		if (p[i].a==p[i-1].a && i!=1){
			ok1++;
		}
		for (int j=1;j<=p[i].c;j++){
			s.push_back(p[i].a);
		}
	}
	if (sum%2==0){
		if (n%2==1){
			if (!ok){
				cout<<(sum-2)/2;
				return 0;
			}
		}
		else{
			if (!ok){
				cout<<sum/2;
				return 0;
			}
		}
	}
	if (n==1){
		cout<<0;
		return 0;
	}
	if (ok1==n-1){
		cout<<0;
		
	}
    string s1;
    for (int i=s.size()-1;i>=0;i--){
    	s1.push_back(s[i]);
	}
	int m=s1.size(),t=s1.size();
	int ans=0;
	while (t-- && t>0){
		if (s[t]!=s1[m-t]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
