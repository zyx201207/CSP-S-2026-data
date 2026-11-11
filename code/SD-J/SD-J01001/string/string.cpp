#include<bits/stdc++.h>
using namespace std;
struct ss{
	long long a;
	char c;
}x[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long max_ret=-1;
    for(int i=1;i<=n;i++){
    	cin>>x[i].a>>x[i].c;
    	max_ret=max(x[i].a,max_ret);
	}
    if(max_ret*n<=10000){
    	string s;
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=x[i].a;j++) s+=x[i].c;
	    }
        int l2=0,r2=s.size()-1;
    	while(l2<r2){
	    	if(s[l2]!=s[r2]) ans++;
	    	l2++;
	     	r2--;
    	}
    	cout<<ans;
    	return 0;
	}
    long long ret=0;
	int l=1,r=n;
    while(l<r){
    	ret=min(x[l].a,x[r].a);
		x[r].a-=ret;
    	x[l].a-=ret;
		if(x[l].c!=x[r].c) ans+=ret;
		if(x[l].a==0&&x[r].a==0) l++,r--;
		else if(x[l].a!=0&&x[r].a==0) r--;
		else if(x[l].a==0&&x[r].a!=0) l++;
	}
	cout<<ans;
	return 0;
} 
