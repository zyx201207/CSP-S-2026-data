#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=1000005;
int n,m,a[maxN],d[maxN],s,ans,le;
int main(){
	freopen("crystal2.in ","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
	cin>>a[i];
	d[i-1]=a[i]-a[i-1];
}

for(int front=1;front<n;front++){
s=0;
	for(int rear=front;rear<n;rear++){
		if(s+(rear-front+1)*d[rear]>m) continue;
else {s=s+(rear-front+1)*d[rear];
ans=max(ans,rear-front+1);}
}
}
cout<<ans;

return 0;	
}



 
