#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[200009],n;
	long long sum=0,cache,cache1,ans=0,p;
	char b[200009];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin >> a[i]>>b[i];
		sum+=a[i];
	}
	if(sum%2==0) cache=sum/2;
	else cache=sum/2+1;
	cache1=cache;
	int j=1;
	while(cache>a[j]){
		cache-=a[j];
		j++;
	}
	p=a[j];
	p-=cache;
	long long b1=a[1],b2=p,b3=1,b4=j;
	while(cache1>0){
		cache1-=min(b1,min(b2,cache));
		if(b[b3]!=b[b4]) ans+=min(b1,min(b2,cache));
		b1-=min(b1,min(b2,cache));
		b2-=min(b1,min(b2,cache));
		if(b1==0){
			b3++;
			b1=a[b3]; 
	    }
	    if(b2==0){
		    b4++;
		    b2=a[b4]; 
	    }
	}
    if(sum%2==1) ans=ans-1;
	cout << ans;
    return 0;
}


