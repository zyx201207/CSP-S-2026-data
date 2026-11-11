#include<bits/stdc++.h> 
using namespace std;
bool sane=1;
int n;
long long l,maxn=LLONG_MIN;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<long long> a(n+1),shuliang(27);
	vector<char> c(n+1);
	for(int i=1;i<=n;i++){
	   cin>>a[i]>>c[i];
	   if(c[i]!=c[i-1]){
	      sane=0;
		}
	    shuliang[int(c[i]-96)]+=a[i];
	    l+=a[i];
    }
    if(sane){
    	cout<<0<<'\n';
    	return 0;
	}
    for(int i=1;i<=26;i++)
       maxn=max(maxn,shuliang[i]);
	if(!(l&1)) cout<<l-maxn;
    else  cout<<l-maxn-1; 
	return 0;
}
